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

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

vector<int> SieveOfEratosthenes(int n)
{
    vector<bool> isPrime(n + 1, true);
    for (int p = 3; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    vector<int> primes;
    FOR(i,3, n + 1)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    FOR(i,0,n)
        cin >> a[i];
    
    vector<int> primes = SieveOfEratosthenes(n);
    
    for (int prime : primes){
        if (n % prime != 0)
            continue;

        for (int k = 0; k < n / prime; k++){
            bool flag = false;
            for (int i = k; i < n; i += n / prime)
                if (a[i] == 0){
                    flag = true;
                    break;
                }
            if (!flag){
                cout << "YES" << endl;
                return;
            }
        }
        
    }

    cout << "NO" << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}