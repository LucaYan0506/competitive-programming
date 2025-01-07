#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

int msbVal(int x){
    int res = 1;
    while(res * 2 <= x)
        res *= 2;

    return res;
}

void solve(){
    int l,r; cin >> l >> r;
    int k = msbVal(l ^ r);
    int a = k;

    int temp = l;
    while(temp > k){
        int temp2 = msbVal(temp);
        a += msbVal(temp);
        
        temp -= temp2;
    }
    
    int b = a - 1, c = 0;
    FOR (i, l, r + 1)
        if (i != a && i != b){
            c = i;
            break;
        }
    
    cout << a << " " << b << " " << c << "\n";
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}