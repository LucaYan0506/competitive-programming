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
    int n,m,k; cin >> n >> m >> k;
    m++,k++;//1-indexed
    vector<int> t(n);
    FOR(i,0,n)
        cin >> t[i];
    vector<vector<int>> cost(n,vector<int>(m));
    FOR(i,0,n)
        FOR(j,1,m)
            cin >> cost[i][j];
    
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(k,vector<int>(m,oo)));
    FOR(j,1,m){
        if (t[0] != 0){
            if (t[0] == j)
                dp[0][1][j] = 0;
            else
                continue;
        }else{
            dp[0][1][j] = cost[0][j];
        }
    }

    
    FOR(i,1,n)
    FOR(ki,1,k)
    FOR(j,1,m){
        if (t[i] != 0){
            if (t[i] == j){
                FOR(ci,1,m){
                    if (ci != j)
                        dp[i][ki][j] = min(dp[i][ki][j], dp[i - 1][ki - 1][ci]);
                    else
                        dp[i][ki][j] = min(dp[i][ki][j], dp[i - 1][ki][ci]);
                }
            }else{
                continue;
            }
        }else{
            FOR(ci,1,m){
                if (ci != j)
                    dp[i][ki][j] = min(dp[i][ki][j], dp[i - 1][ki - 1][ci] + cost[i][j]);
                else
                    dp[i][ki][j] = min(dp[i][ki][j], dp[i - 1][ki][ci] + cost[i][j]);
            }
        }
    }
    int res = oo;
    FOR(j,1, m)
        res = min(res, dp[n - 1][k - 1][j]);

    if (res > 1e12)
        cout << -1 << endl;
    else
        cout << res << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}