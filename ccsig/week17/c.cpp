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
const int T = 100;
vector<vector<vector<bool>>> statue(8,vector<vector<bool>>(8,vector<bool>(T)));
vector<vector<vector<int>>> dp(8,vector<vector<int>>(8,vector<int>(T,-1)));

vector<pair<int,int>> dirs = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
    {-1,-1},
    {1,-1},
    {-1,1},
    {1,1},
};

bool rec(int i, int j, int t){
    if (i < 0 || i >= 8 || j < 0 || j >= 8 || t < 0)
        return false;

    if (statue[i][j][t])
        return false;
    
    if (dp[i][j][t] != -1)
        if (dp[i][j][t]){
            cout << i << " " << j << " " << t << endl;
            return dp[i][j][t];
        }
    dp[i][j][t] = false;
    for (auto dir : dirs)
        dp[i][j][t] = dp[i][j][t] || rec(i + dir.first, j + dir.second, t - 1); 

    return dp[i][j][t];
}

void solve(){
    vector<string> grid(8);
    dp[7][0][0] = true;
    FOR(i,0,8)
        cin >> grid[i];

    FOR(t,0,T)
        FOR(i,t,8)
            FOR(j,0,8)
                if (grid[i - t][j] == 'S')
                    statue[i][j][T] = true;
        
    FOR(t,0,T)
        if (rec(0,6,t) == 1 ){
            cout << "WIN" << endl;
            return;
        }

    cout << "LOSE" << endl;

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}