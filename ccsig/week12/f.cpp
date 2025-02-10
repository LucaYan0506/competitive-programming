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
    // FOR(i,5, 25)
    //     cout << i << " = " << (i*i - i) / 2 << " " << ((i*i - i) / 2) % i <<  endl;

    int n, p; cin >> n >> p;
    n;
    int count = 1;
    vector<int> edges(n + 1);
    set<pair<int,int>> visited;
    int start = 0;
    int end = start + count;
    visited.insert({start,end});
    FOR(i,0, 2*n + p){
        cout << start + 1 << " " << end + 1 << endl;
        
        start = end;
        end = (start + count) % n;
        if (visited.count({start,end})){
            if ((i + 1) % n == 0){
                count++;
                start = 0;
            }else{
                start++;
            }
            end = (start + count) % n;
            visited.insert({start,end});
            visited.insert({end,start});
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