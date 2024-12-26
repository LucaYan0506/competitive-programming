#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>

using namespace std;
                                                                
bool dfs(int i, vector<set<int>> &edges, vector<bool> &visited,vector<bool> &recursion_stack){
    if (visited[i])
        return true;
    visited[i] = true;

    for (auto x : edges[i]){
        if (recursion_stack[x])
            return false;

        recursion_stack[x] = true;
        if (!dfs(x,edges,visited,recursion_stack))
            return false;
        recursion_stack[x] = false;
    }

    return true;
}

int main(){
    int t; cin >> t;
    vector<string> res;
    while(t--){
        int n,k; cin >> n >> k;
        vector<set<int>> edges(n + 1);
        for (int i = 0; i < k; i++){
            vector<int> a(n);
            for (int j = 0; j < n; j++)
                cin >> a[j];
            
            for (int p = 1; p < n - 1; p++)
                edges[a[p]].insert(a[p + 1]);
        }

        bool flag = true;
        vector<bool> visited(n + 1);
        vector<bool> recursion_stack(n + 1);
        for (int i = 1; i < edges.size(); i++){
            if (visited[i])
                continue;
            recursion_stack[i] = true;
            if (!dfs(i,edges,visited,recursion_stack)){
                flag = false;
                 break;
            }
            recursion_stack[i] = false;
        }
        if (flag)
            res.push_back("YES");
        else
            res.push_back("NO");

        // for (int i = 0; i < edges.size(); i++){
        //     if (visited[i])
        //         continue;
        //     visited[i] = true;
        //     queue<int> q;
        //     for (auto x : edges[i])
        //         q.push(x);
            
        //     while(!q.empty()){
        //         int size = q.size();
        //         while(size--){
        //             auto curr = q.front();
        //             q.pop();
        //             if (visited[curr]){
        //                 flag = true;
        //                 break;
        //             }
        //             for (auto x : edges[curr])
        //                 q.push(x);
        //         }

        //         if (flag)
        //             break;
        //     }

        //     if (flag)
        //         break;
        // }

      
    }

    for (auto x : res)
        cout << x << endl;



    return 0;
}