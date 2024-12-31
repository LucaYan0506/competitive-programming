#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}


int bs(int left, int right, int k) {
    if (right - left + 1 < k)
        return 0;

    if ((right - left + 1) % 2 == 0){
        int mid = (right + left) / 2;
        return bs(left, mid, k) + bs(mid + 1, right, k);
    }else{
        int mid = (right + left) / 2;
        cout << mid << endl;
        return mid + bs(left, mid - 1, k) + bs(mid + 1, right, k);
    }
}


int32_t main(){
    fastIO();
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n, k; cin >> n >> k;
        res.push_back(bs(1,n,k));
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}