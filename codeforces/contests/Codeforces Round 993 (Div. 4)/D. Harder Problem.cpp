#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int main(){
    int t; cin >> t;
    vector<vector<int>> res;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        vector<bool> used(n + 1);
        for (int i = 0 ; i < n; i++)    
            cin >> a[i], used[a[i]]=true;

        vector<int> b(n, -1);
        queue<int> q;
        
        for(int i = 1; i < used.size(); i++)
            if (used[i] == 0)
                q.push(i);
            
        for (int i = 0; i < n; i++){
            if (used[a[i]])
                b[i] = a[i];
            used[a[i]] = false;
        }

        for (int i = 0; i < n; i++)
            if (b[i] == -1){
                b[i] = q.front();
                q.pop();
            }

        res.push_back(b);

    }

    for (auto b : res){
        for (auto x : b)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}