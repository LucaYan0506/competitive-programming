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

vector<int> a;
vector<int> count;

pair<int,int> func(int i){
    int n = a.size();
    int left = i;
    int right = a.size();
    while (left < right)
    {
        int mid = (right + left) / 2;
        FOR(j,0, n){
            if (j <= mid)
                newCount += (a[i] < a[j]);
            else
                newCount += (a[i] > a[j]);
        }
    }
    
}


void solve(){
    int n; cin >> n;
    a = vector<int>(n);
    FOR(i,0,n)
        cin >> a[i];

    vector<int> count(n,0);
    FOR(i,0,n)
        FOR(j,i + 1, n)
            if (a[i] > a[j])
                count[i]++;
    
    int left = 0, right = 0;
    int minCount = 0;
    FOR(i,0,n){
        auto currCount = func(i);
        if (currCount.first < minCount){
            minCount = currCount.first;
            left = i;
            right = currCount.second;
        }
    }
    cout << left + 1 << " " << right + 1 << endl;    

}
int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}