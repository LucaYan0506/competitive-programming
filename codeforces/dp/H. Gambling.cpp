#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include <fstream>

using namespace std;
#define ll long long

int main(){
    ll t; cin >> t;
    vector<vector<ll>> res;
    while(t--){
        ll n; cin >> n;
        vector<ll> xs(n);
        map<ll,ll> pos;
        map<ll,ll> pos_reverse;
        ll index = 0;
        // set<ll> unique;
        for (ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            if (pos.count(temp) == 0)
                pos[temp] = index++;

            xs[i] = pos[temp];
            pos_reverse[pos[temp]] = temp;
        }

        vector<vector<ll>> dp(n + 1,vector<ll>(3,-1));
        vector<ll> maxE = {-1,-1,-1};
        for (ll i = 0; i < n; i++){
            ll x = xs[i];
            if (dp[x][2] - (i - dp[x][1]) + 1 <= 0){
                dp[x] = {i,i,1};
            }else{
                dp[x] = {dp[x][0],i,dp[x][2] - (i - dp[x][1]) + 1 + 1 };
            }

            if (maxE[2] < dp[x][2]){
                maxE = dp[x];
                maxE.push_back(pos_reverse[x]);
            }
        }

        res.push_back(maxE);

    }

    for (auto x : res){

        cout << x[3] << " " << (x[0] + 1) << " " << (x[1] + 1) << endl;
    }




    return 0;
}