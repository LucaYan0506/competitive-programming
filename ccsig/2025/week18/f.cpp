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

static bool cmp(int a, int b){
    return a > b;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> count(1e6);
    int maxH = 0;
    int minH = INT_MAX;
    FOR(i,0,n){
        int h; cin >> h;
        maxH = max(maxH,h);
        minH = min(minH,h);
        count[h]++;
    }
    int res = 0;
    int curr = 0;
    while (maxH > minH)
    {
        if (curr + count[maxH]> k){
            res++;
            curr = count[maxH];
        }else
            curr += count[maxH];
        
        count[maxH - 1] += count[maxH];
        maxH--;
    }

    res += curr > 0;

    cout << res << endl;
    
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}