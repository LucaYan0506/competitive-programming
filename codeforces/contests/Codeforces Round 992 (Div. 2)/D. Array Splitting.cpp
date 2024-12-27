#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long 

using namespace std;
static bool cmp(ll a, ll b){
    return a > b;
}
int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> preffixSum(n);
    ll sum = 0;
    for (ll i = n - 1; i >= 0; i--){
        sum += a[i];
        preffixSum[i] = sum;
    }

    ll res = preffixSum[0];
    sort(preffixSum.rbegin() + 1, preffixSum.rend());
    for (ll i = 1; i < k; i++)
        res += preffixSum[i];

    cout << res;
    return 0;
}
