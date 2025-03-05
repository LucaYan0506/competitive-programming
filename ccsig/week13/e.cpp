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
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n+1, vector<int>(n+1,0));
    FOR(i,0,m){
        int a,b,debit;
        cin >> a >> b >> debit;
        edges[a][b] += -debit;
    }

    //get credit
    FOR(a,0,n + 1)
        FOR(b,0,n + 1)
            if (edges[a][b] < 0)
                edges[b][a] += (edges[a][b] * -1);

    FOR(a,0,n + 1){
        int credit = 0;
        FOR(b,0,n + 1)
            if (edges[a][b] > 0)
                credit += edges[a][b];

        FOR(b,0,n + 1){
            int debit = edges[a][b];
            if (debit < 0){
                // edges[b][a] += (debit * -1);
                if (credit + debit > 0){
                    credit += debit;
                    edges[a][b] = 0;
                }else{
                    edges[a][b] += credit;
                    credit = 0;
                }
            }

        }
    }
    int res = 0;
    FOR (a, 0, n + 1)
        FOR (b,0,n + 1)
            if (edges[a][b] < 0)
                res += abs(edges[a][b]);
    
    cout << res << endl;
    
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}