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
vector<int> mark; //-1 unvisited 0 and 1 are marks
vector<vector<int>> edges;
vector<int> graph1;
vector<int> graph2;
bool imp = false;
void dfs(int i, int local_mark){
    if (mark[i] != -1){
        if (local_mark == mark[i])
            return;
        imp = true;
        return;
    }

    mark[i] = local_mark;
    for(auto edge : edges[i])
        dfs(edge, !local_mark);
}

void solve(){
    int n,m; cin >> n >> m;
    n++;
    edges = vector<vector<int>>(n);
    mark = vector<int>(n, -1);
    FOR(i,0,m){
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    FOR(i,1,n)
        if (mark[i] == -1)
            dfs(i,1);

    if (imp)
        cout << -1 << endl;
    else{
        int count = 0;
        FOR(i,1,n)
            if (mark[i] == 1)
                count++;

        cout << count << endl;
        FOR(i,1,n)
            if (mark[i] == 1)
            cout << i << " ";
        cout << endl;

        cout << n - count - 1 << endl;
        FOR(i,1,n)
            if (mark[i] == 0)
                cout << i << " ";

    }
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}