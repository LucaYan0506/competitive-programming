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
    vector<int> h(n);
    FOR(i,0,n)
        cin >> h[i];
    
    sort(all(h),cmp);
    
    int res = 0;
    int count = 0;  
    int prevCutI = -1;
    int prevCount = 0;

    FOR(i,0,n - 1){
        int diff = h[i] - h[i + 1];
        if (count > 0 && diff > k) {
            count = 0;
            res++;
            prevCutI = i - 1;
        }

        if (count == 0)
            while(diff > k){
                res++;
                diff -= k; 
                prevCutI = i - 1;
            }

        count += (i - prevCutI) * diff;

        if (h[i] == h[n - 1]){
            res += count > 0;
            count = 0;
            break;
        }
        
        if (count > k){
            prevCutI = i;
            count = count - prevCount;
            prevCount = 0;
            res++;
        }else
        prevCount = count;
    }
    res += count > 0;
    cout << res << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}