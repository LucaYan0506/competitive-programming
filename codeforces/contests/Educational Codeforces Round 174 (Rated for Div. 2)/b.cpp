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

void solve(){
    int n,m; cin >> n >> m;
    vector<int> c(n*m + 1,0);
    vector<vector<int>> grid(n,vector<int>(m));
    FOR(i,0,n)
        FOR(j,0,m)
            cin >> grid[i][j];

    FOR(i,0,n)
        FOR(j,0,m){
            if (i > 0  && grid[i][j] == grid[i - 1][j])
                c[grid[i][j]] = MIN(c[grid[i][j]] + 1, 2);
            else if (j > 0 && grid[i][j] == grid[i][j - 1])
                c[grid[i][j]] = MIN(c[grid[i][j]] + 1, 2);
            else  
                c[grid[i][j]] = MAX(1,c[grid[i][j]]);
        }
    
    sort(all(c));
    int res = 0;
    if (c[c.size() - 2] == 0){
        cout << 0 << endl;
        return;
    }
    FORI(i,c.size() - 2, -1)
        res+=c[i];
    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}