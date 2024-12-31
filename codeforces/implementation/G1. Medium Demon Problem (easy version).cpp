#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}

vector<int> visited;//visited[i] = 0 <- unvisited visited[i] = -1 <- cycle 
int maxi;
int dfs(vector<int> &edges, int i, bool &isCycle){
    if (visited[i] == -1){
        return 2;
    }
    if (visited[i] > 1)
        return visited[i];
    if (visited[i] == 1){
        isCycle = true;
        visited[i] = -1;
        return 2;
    }

    visited[i] = 1;
    int temp = dfs(edges,edges[i],isCycle);
    if (temp == 2 && visited[i] == -1){
        isCycle = false;
        return 2;
    }else if (temp == 2 && isCycle){
        visited[i] = -1;
        return 2;
    }

    visited[i] = temp  + 1; 
    return visited[i];
}


int32_t main(){
    fastIO();
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n; cin >> n;
        vector<int>edges(n);
        visited = vector<int>(n,0);
        maxi = 2;
        for (int i = 0; i < n; i++){
            cin >> edges[i];
            edges[i]--;
        }

        vector<int> inDegree(n,0);
        for (auto x : edges)
            inDegree[x]++;

        for (int i = 0; i < n; i++){
            if (inDegree[i] == 0){
                bool isCycle = false;
                maxi = max(maxi,dfs(edges,i,isCycle));
            }
        }
        res.push_back(maxi);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}