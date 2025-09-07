#include<bits/stdc++.h>

#define int unsigned long long
#define double long double 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define oo 1000000000000000000ll

using namespace std;

random_device dev;
mt19937 rng(dev());
int get_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}
const int MOD =998244353;

vector<int> fact;

// int fact(int n){
//     int res = 1;
//     FOR(i,1,n+1){
//         res *= i;
//         res %= MOD;
//     }
//     return res;
// }

int customPow (int base, int exp){
    base %= MOD;
    int res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int modInverse(int x) {
    return customPow(x, MOD-2); // Fermat
}

int ncr(int n, int r) {
    int denom = (fact[r] * fact[n-r]) % MOD;
    int a = modInverse(denom);
    return fact[n] * modInverse(denom) % MOD;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> d(n);
    FOR(i,0,n)
        cin >> d[i];
    
    vector<int> prefixSum(n + 1);
    FOR(i,0,n)
        prefixSum[i + 1] = prefixSum[i] + d[i];
    int pairCount = 0; // number of pair of points with angle 180
    
    if (prefixSum[n] % 2 == 0)
        FOR(i,1,n)
            pairCount += binary_search(prefixSum.begin() + i + 1, prefixSum.end(),prefixSum[i] + prefixSum[n]/2);
    
    fact.push_back(1);
    FOR(i,1,max(pairCount,m) + 2)
        fact.push_back((fact[fact.size() - 1] * i) % MOD);

    int remainingP = n - pairCount * 2;
    int res = 0;
    FOR(i,0,min(m,pairCount) + 1){
        int temp = ncr(pairCount,i);
        temp = temp * ncr(m,i) % MOD;
        temp = temp * fact[i] % MOD;
        temp = temp * customPow((m-i)*(m-i-1) % MOD, pairCount - i) % MOD;
        temp = temp * customPow(m-i, remainingP) % MOD;
        res = (res + temp) % MOD;
    }
    
    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}