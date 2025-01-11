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
    int n,x,y; cin >> n >> x >> y;
    vector<int> xs(x);
    FOR (i, 0, x)
        cin >> xs[i];
    sort(all(xs));
    int count = 0;
    FOR (i, 1, n){
        int diff = xs[i] - xs[i - 1];
        if (diff < 2)
            continue;
        
        if (y >= diff - 2){
            count += (diff - 1);
            y -= (diff - 2);
        }else{
            count += y;
            y = 0;
        }
    }

}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}