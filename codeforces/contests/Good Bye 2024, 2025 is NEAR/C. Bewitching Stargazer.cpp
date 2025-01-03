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
    int n,k; cin >> n >> k;
    int sum = 0, curr = 1;
    int temp = n;
    while (temp >= k){
        if (temp & 1)
            sum += curr;
        temp >>= 1;
        curr <<= 1;
    }
    int res = (n + 1) * sum / 2;
    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}