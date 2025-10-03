#include<bits/stdc++.h>

#define int long long 
#define double long double
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define oo 1000000000000000000ll

const int mod = 1e9+7;
using namespace std;


void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

void solve(){
    int n,m,k; cin >> n >> m >> k;
    int target = n*(n+1)/2 - k;
    if (target % 2){
        cout << 0 << endl;
        return;
    }

    target /= 2;
    int min_sum = m * (m + 1) / 2;
    int max_sum = 0;
    FOR(i, n - m + 1, n + 1)
        max_sum += i;
    
    if (target > max_sum || target < min_sum){
        cout << 0 << endl;
        return;
    }

    vector<int> res(m);
    FOR(i,1,m+1)
        res[i - 1] = i;

    int diff = target - m*(m+1)/2;
    FORI(i, m-1, -1){
        int t = min(diff, n - (m - i - 1) - res[i]);
        res[i] += t;
        diff -= t;
        if (diff == 0)
            break;
    }

    FOR(i,0,m)
        cout << res[i] << " ";
    cout << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;while(t--)
        solve();

    return 0;
}