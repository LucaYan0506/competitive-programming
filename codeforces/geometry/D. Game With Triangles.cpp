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

vector<int> prefixA;
vector<int> prefixB;

int f(int a, int b, int n, int m){
    // if (a * 2 + b > n)
    //     return -1;

    // if (b * 2 + a > m)
    //     return -1;

    if (a == 0)
        return prefixB[b-1];
    if (b == 0)
        return prefixA[a-1];

    return prefixA[a-1] + prefixB[b-1];
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    
    FOR(i,0,n)
        cin >> A[i];
    FOR(i,0,m)
        cin >> B[i];
    sort(all(A));
    sort(all(B));
    prefixA = vector<int>(n / 2);
    prefixB = vector<int>(m / 2);

    int prev = 0;
    FOR(i,0,n/2){
        prefixA[i] = prev + abs(A[i] - A[n - i - 1]);
        prev = prefixA[i];
    }
    prev = 0;
    FOR(i,0,m/2){
        prefixB[i] = prev + abs(B[i] - B[m - i - 1]);
        prev = prefixB[i];
    }

    vector<int> res;
    int k = 1;

    for(int x = 1; 2*x - m <= n - x; x++){
        // ternary_search
        int l = max(0ll,2*x-m), r = min(x,n-x);
        if(l>r)
            break;

        while(r - l > 3){
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (f(m1, k - m1, n, m) < f(m2, k - m2, n, m))
                l = m1;
            else 
                r = m2;
        }

        int localMax = -1;
        FOR(i, l, r + 1)
            localMax = max(f(i, k - i, n, m), localMax);

        res.push_back(localMax);
        k++;
    }

    cout << res.size() << endl;
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}