#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b, step) for (int i = (a); i < (b); i += (step))
#define endl "\n"

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

void solve(){
    int n,m; cin >> n >> m;
    cout << max(n,m) + 1 << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}