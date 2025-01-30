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
    vector<int> vect(n);
    FOR(i,0,n)
        cin >> vect[i];

    int inValid = 0; 
    FOR (i,0,n){
        int temp; cin >> temp;
        vect[i] -= temp;
        inValid += (vect[i] < 0);
    }

    if (inValid == 0)
        cout << "YES" << endl;
    else if (inValid > 1)
        cout << "NO" << endl;
    else{
        int mini = INT_MAX;
        int amountNeeded = 0;
        for (int x : vect){
            if (x < 0){
                amountNeeded = x * (-1);
                continue;
            }

            mini = min(x, mini);
        }
        if (amountNeeded <= mini)
            cout << "YES" << endl;
        else    
            cout << "NO" << endl;
    }
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}