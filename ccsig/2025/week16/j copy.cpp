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

vector<int> dp(20,-1);
int res;

int func(int n){
    if (dp[n] != -1)
        return dp[n];

    dp[n] = func(n - 1) * 9 + pow(10,n - 1);

    return dp[n];
}

void rec(int n, int d){
    if (n == 0) 
        return;

    string str = to_string(n);
    int firstDigit = str[0] - '0';
    int nines = pow(10,str.size() - 1) - 1;
    if (nines != 0)
        res += func(to_string(nines).size());
    
    int next = n - firstDigit * pow(10,str.size() - 1);

    if (firstDigit == d){
        if (nines != 0)
            res += func(to_string(nines).size()) * (firstDigit - 1);
        res += next + 1;
    }else if (firstDigit > d){
        if (nines != 0)
            res += func(to_string(nines).size()) * (firstDigit - 2);
        
        res += pow(10,str.size() - 1);
        rec(next, d);
    }else{
        if (nines != 0)
            res += func(to_string(nines).size()) * (firstDigit - 1);
        rec(next, d);
    }
}

void solve(){
    res = 0;
    dp[0] = 0;
    dp[1] = 1;
    int n, d; cin >> n >> d;

    rec(n,d);

    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
} 