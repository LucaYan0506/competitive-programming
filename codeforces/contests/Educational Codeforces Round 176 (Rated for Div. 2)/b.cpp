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

static bool cmp(int a,int b){
    return a > b;
}

int helper(vector<int> a, int remaining){
    int n = a.size();

    while(remaining > 1){
        int mini = INT_MAX;
        int index = -1;
        FOR(i,0,n){
            if (a[i] == -1)
                continue;
            if (remaining == 1)
                break;
    
            //can change to blue
            bool flag = false;
    
            if (i - 1 >= 0 && a[i - 1] == -1)
                flag = true;
            if (i + 1 < n && a[i + 1] == -1)
                flag = true;
            if (a[i] < mini){
                mini = a[i];
                index = i;
            }
        }
        a[index] = -1;
        remaining--;
    }
    
    int res = 0;
    FOR(i,0,n)
        if (a[i] != -1){
            res = a[i];
            break;
        }

    return res;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int>a(n);
    FOR(i,0,n)
        cin >> a[i];

    vector<int> sortedA = a; 
    sort(all(sortedA),cmp);
    int res = 0;
    FOR(i,0,k - 1)
        res += sortedA[i];

    //update a
    FOR(i,0,k - 1){
        FOR (j,0,n){
            if (sortedA[i] == a[j]){
                a[j] = -1;
                break;
            }
        }
    }  

    int maxi = 0;

    FOR(i,0,n){
        if (a[i] == -1)
            continue;
        int localRes = a[i];
        int prevA = a[i];
        a[i] = -1;
        maxi = max(localRes + helper(a, n - k), maxi);
        a[i] = prevA;
    }
    res += maxi;
    cout << res << endl;

}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}