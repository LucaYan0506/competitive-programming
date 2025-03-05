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

vector<bool> visited;
vector<vector<int>> edges;

void dfs(int i, int & verticesCount, int & edgesCount) {
    if (visited[i])
        return;
	visited[i] = true;
	verticesCount++;
	edgesCount += edges[i].size();
	for(int x : edges[i])
		if(!visited[x])
			dfs(x, verticesCount, edgesCount);
}

void solve(){
    int n,m; cin >> n >> m;
    edges = vector<vector<int>>(n + 1);
    FOR(i,0,m){
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited = vector<bool>(n + 1,false);
    FOR(i,1,n + 1){
        if (!visited[i]){
            int verticesCount = 0, edgesCount = 0;
            dfs(i, verticesCount,edgesCount);
            if ((verticesCount * (verticesCount - 1)) != edgesCount){
                cout << "NO" << endl;
                return;
            }
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