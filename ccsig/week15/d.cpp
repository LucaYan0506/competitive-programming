#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()

const int mod = 1e9+7;
using namespace std;

vector<int> SieveOfEratosthenes(int n){
    vector<bool> isPrime(n + 1, true);
    for (int p = 2; p * p <= n; p++) 
        if (isPrime[p] == true) 
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;

    vector<int> primes;
    FOR(i,2, n + 1)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

vector<int> graph;

void dfs(vector<vector<int>> edges, int i, int index){
    if (graph[i] != -1)
        return;

    graph[i] = index;
    for (auto edge : edges[i])
        dfs(edges, edge, index);

}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    vector<int> edgeCount(n + 1);
    FOR(i,0,m){
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);

        if (a > b)
            edgeCount[b]++;
        else
            edgeCount[a]++;
        
    }

    graph = vector<int>(n + 1,-1);
    int index = 0;
    FOR(i,1,n + 1){
        if (graph[i] != -1){
            continue;
        }
        dfs(edges,i, index);
        index++;
    }
    
    vector<int> vertecesCount(index);
    vector<int> edgesCount(index);
    FOR(i,1,graph.size()){
        vertecesCount[graph[i]]++; 
        edgesCount[graph[i]] += edgeCount[i];
    }

    FOR(i,0,index){
        if (vertecesCount[i] <= 2)
            continue;
        if ((vertecesCount[i] * (vertecesCount[i] - 1)) / 2 != edgesCount[i]){
            cout << "NO" << endl;
            return;
        }

    }
    cout << "YES" << endl;

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}