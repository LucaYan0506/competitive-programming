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
    vector<int> c(501);
    FOR(i,2,501){
        double temp = (i - 1.0) * (i + .0) / 2.0;
        c[i] = ((int)temp);
    }

    vector<int> res;
    int k; cin >> k;
    int i = 500;
    while(k > 0){
        if (k >= c[i]){
            if (res.size() == 0)
                res.push_back(i);
            else
                res.push_back(i - 1);
            k -= c[i];
        }else
            i--;
    }

    int n = 0;
    for (int x : res)
        n += x;

    cout << n << endl;
    if (n == 0)
        return;
    
    FOR(x,0,res[0])
        cout << x << " " << 0 << endl;
    
    int temp = 1;
    FOR(i,1,res.size()){
        FOR(y,0,res[i])
            cout << i - 1 << " " << y + temp << endl;
        
        temp += res[i];
    }
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();


    return 0;
}