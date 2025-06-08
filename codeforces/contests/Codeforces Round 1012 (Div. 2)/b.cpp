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

void solve(){
    int n,m; cin >> n >> m;
    n++,m++;
    vector<vector<vector<bool>>> grid(n, vector<vector<bool>>(m,vector<bool>(2,0)));
    FOR(i,0,n)
        grid[i][0][0] = 1,
        grid[i][0][1] = 1;
    FOR(j,0,m)
        grid[0][j][0] = 1,
        grid[0][j][1] = 1;
    FOR(i,1,n){
        string temp; cin >> temp;
        FOR(j,1,m)
            grid[i][j][0] = temp[j - 1] == '1',
            grid[i][j][1] = temp[j - 1] == '1';
    }
    //[0] left                   [1] top
    FOR(i,1,n)
        FOR(j,1,m){
            if (grid[i][j][0] == 0)
                continue;
            
            if (grid[i - 1][j][1] == 0 && grid[i][j - 1][0] == 0){
                cout << "NO" << endl;
                return;
            }

            grid[i][j][1] = grid[i - 1][j][1];
            grid[i][j][0] = grid[i][j - 1][0];
        }
    
    cout << "YES" << endl;

}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}