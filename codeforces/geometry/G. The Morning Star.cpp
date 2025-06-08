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
    // map1[x] means number of points that are in the '/' line and passes point {x,0}
    map<int, int> map1;
    // map2[x] means number of points that are in the '\' line and passes point {x,0}
    map<int, int> map2;
    // map3[x] means number of points that are in the '|' line and passes point {x,0}
    map<int, int> map3;
    // map4[y] means number of points that are in the '-' line and passes point {0,y}
    map<int, int> map4;

    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    FOR(i,0,n)
        cin >> points[i][0] >> points[i][1];

    FOR(i,0,n){
        int delta = points[i][1];
        map1[points[i][0] - delta]++;
        map2[points[i][0] + delta]++;
        map3[points[i][0]]++;
        map4[points[i][1]]++;
    }

    int res = 0;

    for (auto [key,val] : map1)
        // (val)p2 = val*(val-1)
        res += val*(val-1);
 
    for (auto [key,val] : map2)
        // (val)p2 = val*(val-1)
        res += val*(val-1);

    for (auto [key,val] : map3)
        // (val)p2 = val*(val-1)
        res += val*(val-1);

    for (auto [key,val] : map4)
        // (val)p2 = val*(val-1)
        res += val*(val-1);

    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}