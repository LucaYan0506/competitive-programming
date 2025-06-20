#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define oo 1000000000000000000ll

std::random_device dev;
std::mt19937 rng(dev());
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << std::endl;

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
    int n,x,y; cin >> n >> x >> y;
    vector<int> vec(x);
    FOR(i,0,x)
        cin >> vec[i];

    sort(all(vec));
    vec.push_back(vec[0] + n);
    int res = max(0ll,x - 2);

    FOR(i,0,x)
        if (vec[i + 1] - vec[i] == 2)
            res++;

    map<int, int> gapsCount; //gapsCount[3] means number of pairs (vec[i],vec[i+1]) with 3 vertices in between (i.e. vec[i + 1] - vec[i] - 1)
    FOR(i,0,x)
        if (vec[i + 1] - vec[i] - 1 > 2)
            gapsCount[vec[i + 1] - vec[i] - 1]++;

    for (auto [i,val] : gapsCount){
        if (i % 2 == 0)
            continue;
        int count = min(y / (i/2), gapsCount[i]);
        
        y -= (i / 2) * count;
        res += ((i / 2) * 2 + 1) * count;
    }

    res = min(res + y * 2, n - 2);

    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}