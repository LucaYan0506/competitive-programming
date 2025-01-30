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
    vector<int> a(n);
    vector<int> b(n);
    FOR (i, 0, n)
        cin >> a[i];

    FOR (i, 0, n)
        cin >> b[i];

    int i = 0, j = 0;
    FOR (k, 0, n){
        cout << a[i] + b[j] << " ";
        if (k == n - 1)
            continue;
        if (b[j] + a[i + 1] <= b[j + 1] + a[0])
            i++;
        else{
            j++;
            i = 0;
        }
    }
    cout << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}