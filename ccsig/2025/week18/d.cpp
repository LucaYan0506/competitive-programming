#include<bits/stdc++.h>

#define int unsigned long long 
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


int nCr(int n, int r){
    int numerator = 1;
    vector<int> used(r + 1);
    used[0] = true;
    used[1] = true;

    FOR(i,n-r+1,n+1){
        int temp = i;
        FOR(j,2,r + 1){
            if (temp % j == 0 && !used[j]){
                used[j] = true;
                temp /= j;
            }

        }
       
        numerator *= temp;
    }
    int denominator = 1;
    FOR(i,0,r + 1)
        if (!used[i])
            denominator *= i;
    return numerator / denominator;
}

void solve(){
    int n,m,t; cin >> n >> m >> t;
    int res = 0;
    FOR(i,4,t)
        res += nCr(n,i) * nCr(m,t-i);
    
    cout << res << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}