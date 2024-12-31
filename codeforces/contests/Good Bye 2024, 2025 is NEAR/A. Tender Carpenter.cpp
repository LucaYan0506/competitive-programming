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
    vector<string> res;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        bool flag = false;
        for (int i = 0; i < n - 1; i++)
            if (a[i] * 2 > a[i + 1] && a[i + 1] * 2 > a[i]){
                flag = true;
                break;
            }

        if (flag)
            res.push_back("YES");
        else
            res.push_back("NO");
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}