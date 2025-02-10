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

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    FOR(i,0,n)
        FOR(j,0,n)
            cin >> a[i][j];


    vector<vector<int>> suffixSum(n,vector<int>(n));
    FOR(i,0,n)
        FORI(j,n - 1, -1)
            suffixSum[i][j] += a[i][j];
    
    vector<vector<int>> possibleV(n);
    FOR(i,0,n){
        
    }
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}