#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define oo 1000000000000000000ll

const int mod = 1e9+7;
using namespace std;

vector<int> SieveOfEratosthenes(int n){
    vector<bool> isPrime(n + 1, true);
    for (int p = 2; p * p <= n; p++) 
        if (isPrime[p] == true) 
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;

    vector<int> primes;
    FOR(i,2, n + 1)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(m);
    FOR(i,0,m)
        cin >> a[i];
    sort(all(a));
    vector<int> preffixSum(m);
    int tot = 0;
    FOR(i,0,m){
        tot += min(a[i], n - 1);
        preffixSum[i] = tot;
    }

    int res = 0;
    FOR(i,0,m - 1){
        int k = lower_bound(a.begin() + i + 1, a.end(), n - a[i]) - a.begin();
        int size = m - k;
        if (size * min(a[i],n-1) + preffixSum[m - 1] - preffixSum[k - 1] + size - size*n > 0)
            res += size * min(a[i],n-1) + preffixSum[m - 1] - preffixSum[k - 1] + size - size*n;

    }
    
    cout << res * 2 << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}