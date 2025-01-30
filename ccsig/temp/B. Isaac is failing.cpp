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

int tot(vector<int> a){
    int res = 1;
    FOR(i,0,a.size())
        res *= a[i];

    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int maxi = 0;
    FOR (i,0,n)
        cin >> a[i];

    FOR (i, 0, n){
        a[i]++;
        maxi = max(tot(a),maxi);
        a[i]--;

    }

    cout << maxi << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}