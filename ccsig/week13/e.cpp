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
    int n,p; cin >> n>> p;
    p--;
    string s; cin >> s;
    vector<char> a(n);
    FOR(i,0,n){
        a[i] = s[i];
    }

    int l = p, r = p; 
    vector<bool> isInvalid(n);
    FOR(i,0,n/2)
        if (a[i] != a[n - i - 1]){
            isInvalid[i] = true;
            isInvalid[n - i - 1] = true;
            if (p < n / 2){
                l = min(l,i);
                r = max(r,i);        
            }else{
                l = min(l, n - i - 1);
                r = max(r, n - i - 1);
            }
        }

    
    int res = (r - p) + (r - l);
    res = min(res, (p - l) + (r - l)) ;
    FOR(i,l,r + 1){
        if (isInvalid[i]){
            int inverseI = n - i - 1;
            if (p >= n / 2)
                inverseI = abs(i - n + 1);
            int minDist = abs(a[i] - a[inverseI]);
            minDist = MIN(minDist, abs(a[i] - a[inverseI] + 26));
            minDist = MIN(minDist, abs(a[i] - a[inverseI] - 26));
            res += minDist;
        }
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