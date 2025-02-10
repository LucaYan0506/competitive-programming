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
    int n,m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    FOR(i,0,n)
        cin >> a[i];
    FOR(i,0,m)
        cin >> b[i];
    
    sort(all(b));
    int prev = INT_MIN;
    FOR(i,0,n){
        auto j = lower_bound(b.begin(), b.end(), a[i] + prev);
        int temp = INT_MIN;
        if (j != b.end())
            temp = *j - a[i];

        if (temp >= prev && a[i] >= prev)
            a[i] = min(a[i], temp);
        else if (temp >= prev)
            a[i] = temp;
        else if (a[i] >= prev)
            a[i] = a[i];
        else{
            cout << "NO" << endl;
            return;
        }

        prev = a[i];
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