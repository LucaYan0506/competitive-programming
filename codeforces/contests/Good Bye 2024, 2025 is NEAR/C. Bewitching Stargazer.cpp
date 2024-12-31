#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}




int32_t main(){
    fastIO();
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> ks;
        int tempN = n;
        while(tempN > 0){

            tempN /= 2;
            bool flag = tempN % 2 == 1;
            int mid = tempN + 1;
            if (flag)
                ks.push_back(mid);
            if(mid < k)
                break;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (auto _k : ks)
                if (i % _k == 0){
                    ans += i;
                    break;
                }
        res.push_back(ans);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}