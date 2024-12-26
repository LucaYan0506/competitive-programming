#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}

int nPoint(int r){
    int count = 0;
    for (int x = r - 1; x > 0; x--){
        int y = floor(sqrt(r*r - x*x));
        if (y == sqrt(r*r - x*x))
            y--;
        count += y + 1;
    }

    return (count) * 4;
}


int32_t main(){
    fastIO();
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int r; cin >> r;
        res.push_back(nPoint(r + 1) - nPoint(r));
    }

    for (auto x : res)
        cout << x << endl;
    

    return 0;
}