#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <cstdint>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int32_t main(){
    int t; cin >> t;
    vector<string> res;
    while(t--){
        int n,m,k; cin >> n >> m >> k;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
            cin >> a[i];

        vector<bool> q(n + 1);
        for (int i = 0; i < k; i++){
            int temp; cin >> temp;
            q[temp]=true;
        }

        if (k < n - 1){
            string temp = "";
            for (int i = 0; i < m; i++)
                temp += "0";
            res.push_back(temp);
            continue;
        }

        if (k == n){
            string temp = "";
            for (int i = 0; i < m; i++)
                temp += "1";
            res.push_back(temp);
            continue;
        }

        string ans = "";
        for (int x : a){
            if (!q[x])
                ans += "1";
            else
                ans += "0";
        }

        res.push_back(ans);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}