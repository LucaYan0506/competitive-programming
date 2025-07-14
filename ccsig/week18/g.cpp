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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> preffix(n);
    vector<int> suffix(n + 1);
    suffix[n] = 0;
    int tot = 0;
    FOR(i,0,n){
        cin >> a[i];
        tot += a[i];
        preffix[i] += tot;
    }

    FORI(i,n - 1, -1)
        suffix[i] += suffix[i + 1] + a[i];  
    

    if (tot % 3 != 0){
        cout << 0 << endl;
        return;
    }


    //count how many tot/3  the are from n - 1 to i
    vector<int> dp1(n + 1);
    dp1[n] = 0;
    //count how many tot/3 * 2 the are from n - 1 to i
    vector<int> dp2(n + 1);
    dp2[n] = 0;

    FORI(i,n - 1, -1){
        dp1[i] = dp1[i + 1] + (suffix[i] == tot / 3); 
        if (suffix[i] == tot / 3 * 2)
            dp2[i] =  dp1[i + 1];
    }

    int res = 0;
    FOR(i,0,n - 2){
        if (preffix[i] == tot/3)
            res += dp2[i + 1];
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