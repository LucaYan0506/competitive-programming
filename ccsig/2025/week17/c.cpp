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
vector<vector<vector<bool>>> statue(8,vector<vector<bool>>(8,vector<bool>(8)));
vector<vector<vector<int>>> dp(8,vector<vector<int>>(8,vector<int>(8,-1)));

vector<pair<int,int>> dirs = {
    {0,0},
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
    {-1,-1},
    {1,-1},
    {-1,1},
    {1,1},
};

void printDP(){
    FOR(t,0,8){
        cout << "Time: " << t << endl;
        FOR(i,0,8){
            FOR(j,0,8)
                cout << dp[i][j][t] << " ";
            cout << endl;
        }
    }

}   

void printStatue(){
    FOR(t,0,8){
        cout << "Statue: " << t << endl;
        FOR(i,0,8){
            FOR(j,0,8)
                cout << statue[i][j][t] << " ";
            cout << endl;
        }
    }

}            


bool rec(int i, int j, int t){
    if (i < 0 || i >= 8 || j < 0 || j >= 8 || t < 0)
        return false;

    if (statue[i][j][t])
        return false;
    
    if (t > 0 && statue[i][j][t-1])
        return false;
        
    if (dp[i][j][t] != -1)
            return dp[i][j][t];

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

    FOR(t,0,8)
        FOR(i,t,8)
            FOR(j,0,8)
                if (grid[i - t][j] == 'S')
                    statue[i][j][t] = true;
        
    FOR(i,0,8)
        FOR(j,0,8){
            if (rec(i,j,7)){
                cout << "WIN" << endl;
                // printDP();
                // printStatue();
                return;
            }
        }
        // printDP();
        // printStatue();
    cout << "LOSE" << endl;

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}