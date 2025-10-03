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
    int n, x0, y0; cin >> n >> x0 >> y0;
    vector<vector<int>> a(n,vector<int>(2));
    FOR(i,0,n)
        cin >> a[i][0] >> a[i][1];

    set<pair<int,int>> slopes;
    for (auto xy : a){
        int x = xy[0];
        int y = xy[1];
        int a = (y0 - y) / gcd(y0 - y, x0 -x);
        int b = (x0 -x) / gcd(y0 - y, x0 -x);
        if (a < 0 && b < 0)
            a = -a, b = -b;
        else if (a > 0 && b < 0)
            a = -a, b = -b;
        if (x0 -x == 0){
            b = 0;
            a = 1;
        }
        if (y0 - y == 0){
            a = 0;
            b = 1;

        }
            
        slopes.insert({a,b});
    }

    cout << slopes.size() << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}