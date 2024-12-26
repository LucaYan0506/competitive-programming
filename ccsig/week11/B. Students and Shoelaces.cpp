#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<vector<bool>> students(n + 1, vector<bool> (n + 1,false));
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        students[a][b]=true;
        students[b][a]=true;
    }

    int count = 0;
    bool kicked = true;
    while(kicked){
        kicked = false;
        vector<pair<int,int>> reprimandedStudents;
        
        for (int i = 0; i <= n; i++){
            int temp = 0;
            for (int j = 0; j <= n; j++)
                if (students[i][j])
                    temp = j + temp * n * n;
            

            if (temp > 0 && temp <= n){
                reprimandedStudents.push_back({i,temp});
                kicked = true;
            }
        }
        
        for (auto student : reprimandedStudents){
            students[student.first][student.second] = false;
            students[student.second][student.first] = false;
        }

        if (kicked)
            count++;
    }




    cout << count;

    return 0;
}
