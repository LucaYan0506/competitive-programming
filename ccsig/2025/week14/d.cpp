#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()

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
vector<int> a, prefixSum;
string s;
int rec(int n){
    if (n < 0)
        return 0;

    if (s[n] == '0')
        return rec(n - 1);
    if (n == 0)
        return a[0];
    
    return max(prefixSum[n - 1], a[n] + rec(n - 1));
    
}

void solve(){
    int n; cin >> n;
    a = vector<int>(n);
    prefixSum = vector<int>(n);
    FOR(i,0,n){
        cin >> a[i];
        if (i > 0)
            prefixSum[i] = prefixSum[i - 1] + a[i];
        else
            prefixSum[i] = a[i];
    }

    cin >> s;
    cout << rec(n - 1) << endl;

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}