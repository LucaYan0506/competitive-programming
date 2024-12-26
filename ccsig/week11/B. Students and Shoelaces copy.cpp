#include<iostream>
#include<vector>

using namespace std;

int customFind(vector<int> arr, int n){
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == n)    
            return i;

    return arr.size();
}

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> students(n + 1);
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        students[a].push_back(b);
        students[b].push_back(a);
    }

    int count = 0;
    bool kicked = true;
    while(kicked){
        kicked = false;
        vector<int> reprimandedStudents;
        
        for (int i = 0; i <= n; i++){
            if (students[i].size() != 1)
                continue;

            reprimandedStudents.push_back(i);
            kicked = true;
        }
        
        for (auto x : reprimandedStudents){
            int pos = customFind(students[students[x][0]], x);
            if (pos == students[students[x][0]].size())
                continue;
            students[students[x][0]].erase(students[students[x][0]].begin() + pos);
            students[x] = vector<int>();
            
        }

        if (kicked)
            count++;
    }




    cout << count;

    return 0;
}
