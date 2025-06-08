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

void solve(){
    int n; cin >> n;
    vector<int> x(n);
    vector<int> t(n);
    FOR(i,0,n)
        cin >> x[i];

    FOR(i,0,n)
        cin >> t[i];

    int mini = INT_MAX, maxi = INT_MIN;
    FOR(i,0,n){
        x.push_back(x[i] + t[i]);
        x[i] -= t[i];

        mini = min(mini, x[i]);
        mini = min(mini, x[x.size() - 1]);

        maxi = max(maxi, x[i]);
        maxi = max(maxi, x[x.size() - 1]);
    }

    int res = (mini + maxi);
    cout << res / 2;
    if (res % 2 == 1)
        cout << ".5";
    cout << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}