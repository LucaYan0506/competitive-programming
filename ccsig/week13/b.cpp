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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    FOR(i,0,n)
        cin >> a[i];

    int curr = INT_MAX;
    int res = 0;
    FORI(i,n - 1, -1){
        if (curr == 0)
            break;
        if (a[i] < curr){
            res += a[i];
            curr = a[i];
        }else{
            curr--;
            res += curr;
        }
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