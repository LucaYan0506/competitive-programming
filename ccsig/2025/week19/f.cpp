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

static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    FOR(i,0,n){
        cin >> a[i].first;
        cin >> a[i].second;
    }

    sort(all(a),cmp);

    FOR(i,1,n){
        int k = a[i].first -  a[i - 1].first;
        k = pow(4,k);
        a[i].second = max(a[i].second, (a[i - 1].second / k) + (a[i - 1].second % k != 0));
    }

    do{
        a[n-1].first++;
        a[n-1].second = (a[n - 1].second / 4) + (a[n - 1].second % 4 != 0);
    }while(a[n-1].second != 1);

    cout << a[n-1].first << endl;

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}