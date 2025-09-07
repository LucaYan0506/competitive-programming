#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;


void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

vector<vector<int>> adj;
vector<vector<int>> adj_reverse;
vector<bool> visited;
vector<int> canGo;
vector<int> canReach;

void dfs(int i){
    if (visited[i])
        return;

    canGo[i]=true;
    visited[i]=true;
    for (int j : adj[i])
        dfs(j);
}

void dfs2(int i){
    if (visited[i])
        return;

    canReach[i]=true;
    visited[i]=true;
    for (int j : adj_reverse[i])
        dfs2(j);
}

void solve(){
    int n,m; cin >> n >> m;
    adj.resize(n + 1);
    adj_reverse.resize(n + 1);
    visited.resize(n + 1);
    canGo.resize(n + 1);
    canReach.resize(n + 1);

    FOR(i,0,m){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj_reverse[b].push_back(a);
    }

    dfs(1);
    visited = vector<bool>(n+1,false);
    dfs2(1);

    vector<pair<int,int>> res;
    FOR(i,2,n+1){
        if (!canReach[i]){
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return;
        }
        if (!canGo[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    while(t--)
        solve();

    return 0;
}