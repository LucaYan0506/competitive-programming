#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
 
static bool cmp(ll a, ll b){
    return a > b;
}
 
 
int main(){
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n,k; cin >> n >> k;
        string str; cin >> str;
        vector<ll> suffixSum(n - 1);
        ll sum = 0;
        for (int i = n - 1; i > 0; i--){
            if (str[i] == '0')
                sum--;
            else
                sum++;
 
            suffixSum[i - 1] = sum;
        }
 
        sort(suffixSum.begin(),suffixSum.end(),cmp);
        int m = 1;
        sum = 0;
        for (int x : suffixSum){
            sum += x;
            m++;
            if (sum >= k)
                break;
        }
        if (sum >= k)
            res.push_back(m);
        else
            res.push_back(-1);
    }
 
    for (int x : res)
        cout << x << endl;
 
 
    return 0;
}