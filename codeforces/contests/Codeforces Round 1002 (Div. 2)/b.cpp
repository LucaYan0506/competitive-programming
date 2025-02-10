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
    int n,k; cin >> n >> k;
    vector<int> a(n + 1);
    FOR(i,0,n)
        cin >> a[i + 1];
    
    int l = 2;
    int cost = 1;
    vector<bool> valid(2*1e5 + 1);
    while(l <= n){
        int r = l + (n - k);
        for (int j = l; j <= r && j <= n; j++)
            if (a[j] != cost)
                valid[cost] = true;
            else if (a[j] != cost + j - l && cost + j - l < n)
                valid[cost + j - l] = true;

        l+= 2;
        cost++;
    }
    valid[(k / 2) + 1] = true;
    FOR(i,0,valid.size())
        if (valid[i]){
            cout << i << endl;
            return;
        }
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}