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

random_device dev;
mt19937 rng(dev());
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

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

int oddCount(int n){
    return (n + 1) / 2 - 1;
}

int multipleOf4Count(int n){
    return n / 4 - 1;
}

void solve(){
    int n; cin >> n;
    if (n <= 4){
        if (n == 1)
            cout << 3 << endl;
        else if (n == 2)
            cout << 5 << endl;
        else if (n == 3)
            cout << 7 << endl;
        else 
            cout << 8 << endl;

        return;
    }
    int l = 8, r = 1e10;
    while(l <= r){
        int m = (r + l) / 2;
        int curr = oddCount(m) + multipleOf4Count(m);
        if (curr > n)
            r = m - 1;
        else if (curr < n)
            l = m + 1;
        else{
            if (m % 4 == 0 | m % 2 == 1){
                cout << m << endl;
                break;
            }else{
                r = m - 1;
            }
        }
    }

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}