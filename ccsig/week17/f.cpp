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
    int n,m,k; cin >> n >> m >> k;
    int x,s; cin >> x >> s;
    vector<int>a(m);
    vector<int>b(m);
    FOR(i,0,m)
        cin >> a[i];
    FOR(i,0,m)
        cin >> b[i];

    vector<int> c(k);
    vector<int> d(k);
    FOR(i,0,k)
        cin >> c[i];
    FOR(i,0,k)
        cin >> d[i];

    int res = n * x;
    int temp = (upper_bound(all(d),s) - d.begin() - 1);
    if (temp >= 0)
        res = max(0ll,n - a[temp]) * x;
    FOR(i,0,m){
        if (b[i] > s)
            continue;
        int j = upper_bound(all(d),s - b[i]) - d.begin() - 1;
        int localN = n;
        if (j >= 0)
            localN -= c[j];
        res = min(localN * a[i],res);
    }

    cout << res << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}