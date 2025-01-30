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
    int n, a, b; cin >> n >> a >> b;
    bool flag = false;

    while(true){
        if (!flag){
            if (a < b)
                a++;
            else   
                a--;

            if (a == b || a > n || a == 0){
                cout << "NO" << endl;
                return;
            }
        }else{
            if (a < b)
                b--;
            else 
                b++;
            
            if (a == b || b > n || b == 0){
                cout << "YES" << endl;
                return;
            }
        }
        flag = !flag;
    }

}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}