#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b, step) for (int i = (a); i < (b); i += (step))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

void solve(){
    const int N = 200000;
    int n,m,q; cin >> n >> m >> q;
    int a[n];
    int b[m];
    int totA = 0, totB = 0;
    FOR (i,0,n,1)
        cin >> a[i], totA += a[i];
    
    FOR (i, 0, m, 1)
        cin >> b[i], totB += b[i];
    
    bool existAPos[N + 1] = {false};
    bool existBPos[N + 1] = {false};
    bool existANeg[N + 1] = {false};
    bool existBNeg[N + 1] = {false};

    for (int x : a){
        if (abs(totA - x) > N)
            continue;
        if (totA - x > 0)
            existAPos[totA - x] = true;
        else
            existANeg[x - totA] = true;
    }

    for (int x : b){
        if (abs(totB - x) > N)
            continue;
        if (totB - x > 0)
            existBPos[totB - x] = true;
        else
            existBNeg[x - totB] = true;
    }

    FOR (i, 0, q, 1){
        int x; cin >> x;
        bool flag = false;
        FOR (r, 1, (int)(sqrt(abs(x))) + 1, 1){
            if (abs(x) % r != 0)
                continue;
            int c = abs(x) / r;
            if (x >= 0){
                   if (existAPos[r] && existBPos[c]) flag = true, cout << "YES" << "\n";
                   else if (existAPos[c] && existBPos[r]) flag = true, cout << "YES" << "\n";
                   else if (existANeg[r] && existBNeg[c]) flag = true, cout << "YES" << "\n";
                   else if (existANeg[c] && existBNeg[r]) flag = true, cout << "YES" << "\n";
            }else{
                   if (existANeg[r] && existBPos[c]) flag = true, cout << "YES" << "\n";
                   else if (existANeg[c] && existBPos[r]) flag = true, cout << "YES" << "\n";
                   else if (existAPos[r] && existBNeg[c]) flag = true, cout << "YES" << "\n";
                   else if (existAPos[c] && existBNeg[r]) flag = true, cout << "YES" << "\n";
            }

            if (flag)
                break;
        }

        if (!flag)
            cout << "NO" << "\n";
    }

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}