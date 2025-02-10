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

static bool cmp(vector<int>a,vector<int> b){
    int m = a.size() - 1;
    return a[m] > b[m];
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m + 1));
    FOR(i,0,n)
        FOR(j,0,m){
            cin >> a[i][j];
            a[i][m] += a[i][j];
        }

    sort(all(a),cmp);
    int score = 0;
    int currSum = 0;
    FOR(i,0,n)
        FOR(j,0,m){
            score += currSum + a[i][j];
            currSum += a[i][j];
        }

    cout << score << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}