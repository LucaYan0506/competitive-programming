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

static bool cmp(int a,int b){
    return a > b;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int>a(n);
    FOR(i,0,n)
        cin >> a[i];

    vector<int> sortedA = a; 
        
    if (k == 1){
        int res = 0;
        FOR(i,1,n - 1)
            res = max(a[i] + max(a[0],a[n - 1]), res);
        
        res = max(a[0] + a[n - 1], res);
        res = max(a[n - 1] + a[0], res);

        cout << res << endl;
        return;
    }

    sort(all(sortedA),cmp);
    int res = 0;
    FOR(i,0,k + 1)
        res += sortedA[i];

    
    cout << res << endl;

}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}