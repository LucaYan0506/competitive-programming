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
    int xc,yc; cin >> xc >> yc;
    int k; cin >> k;
    vector<vector<int>> vect(k, vector<int>(2));
    FOR(i,0,k)
        cin >> vect[i][0] >> vect[i][1];

    int steps = 0;
    for (auto dir : vect){
        int xSteps = INT_MAX;
        int ySteps = INT_MAX;
        if (dir[0] > 0){
            int diffx = n - xc;
            xSteps = diffx / dir[0];
            if (diffx < 0)
                xSteps = 0;
        }else if (dir[0] < 0){
            int diffx = xc - 1;
            xSteps = abs(diffx / dir[0]);
            if (diffx < 0)
                xSteps = 0;
        }

        if (dir[1] > 0){
            int diffy = m - yc;
            ySteps = diffy / dir[1];
            if (diffy < 0)
                ySteps = 0;
        }else if (dir[1] < 0){
            int diffy = yc - 1;
            ySteps = abs(diffy / dir[1]);
            if (diffy < 0)
                ySteps = 0;
        }
  

        int curr = min(xSteps,ySteps);
        xc += curr * dir[0];
        yc += curr * dir[1];
        steps += curr;
    }
    cout << steps << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}