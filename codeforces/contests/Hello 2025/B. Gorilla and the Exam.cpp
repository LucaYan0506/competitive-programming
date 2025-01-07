#include<bits/stdc++.h>

// #define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b, step) for (int i = (a); i < (b); i += (step))
#define endl "\n"

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

void solve(){
    map<int,int> freq;
    int n,k; cin >> n >> k;
    FOR (i , 0, n, 1){
        int temp; cin >> temp;
        freq[temp]++;
    }
    vector<int> vect;
    for (auto &[key,val] : freq)
        vect.push_back(val);

    sort(vect.begin(), vect.end());
    int count = vect.size();
    for (auto& x : vect){
        if (k - x < 0)
            break;
        k -= x;
        count--;
    }

    cout << max(1,count) << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}