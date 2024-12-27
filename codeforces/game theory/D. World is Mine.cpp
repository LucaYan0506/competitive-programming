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
        int n; cin >> n;
        map<int,int> freq;
        for (int i = 0; i < n; i++){
            int temp; cin >> temp;
            freq[temp]++;
        }

        vector<int> vect;
        for (auto x : freq)
            vect.push_back(x.second);

        vector<vector<int>> dp(vect.size(), vector<int>(vect.size() + 1,INT_MIN));
        dp[0][1] = 1;
        for (int i = 1; i < vect.size(); i++){
            for (int x = 1; x <= i + 1; x++){
                dp[i][x] = max(dp[i - 1][x - 1] + 1, dp[i - 1][x] - vect[i]);
                if (dp[i][x] < 0)
                    dp[i][x] = INT_MIN;
            }
        }   

        for (int x = 0; x <= vect.size(); x++)
            if (dp[vect.size() - 1][x] >= 0){
                res.push_back(x);
                break;
            }
        
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}