#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define oo 1000000000000000000ll

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

vector<int> a;
vector<int> visited;
vector<vector<int>> edges;
int n,m;
int res = 0;

void dfs(int i, int currM){
    visited[i] = true;

    vector<int> unvisitedNodes;
    for (auto x : edges[i])
        if (!visited[x])
            unvisitedNodes.push_back(x);
            
    if (a[i] == 0)
        currM = 0;
    else
        currM++;
    
    //to many cats
    if (currM > m)
        return; 

    //leaf
    if (unvisitedNodes.size() == 0){
        res++;
        return;
    }

    for (auto x : unvisitedNodes)
        dfs(x,currM);
    
}

void solve(){
    cin >> n >> m;
    a = vector<int>(n);
    visited = vector<int>(n);
    edges = vector<vector<int>>(n);
    FOR(i,0,n)
        cin >> a[i];

    FOR(i,0,n -1){
        int x,y; cin >> x >> y;
        x--,y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(0,0);

    cout << res << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}