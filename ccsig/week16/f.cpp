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
    int n, t; cin >> n >> t;
    string a,b; cin >> a >> b;
    int equal = 0;
    FOR(i,0,n)
        if (a[i] == b[i])
            equal++;
    
    if (t < (n - equal + 1) / 2)
        cout << -1 << endl;
    else{
        if (t >= n - equal){
            int count = n - t;
            FOR(i,0,n){
                if (a[i] == b[i] && count > 0){
                    cout << a[i];
                    count--;
                }else{
                    char diff = ((a[i] + 1 - 'a') % 26) + 'a';
                    if (diff == b[i])
                        diff = (diff + 1 - 'a') % 26 + 'a';
                    cout << diff;
                }
            }
        }else{
            bool flag = false;
            int count = 2 * (n - equal - t);
            FOR(i,0,n){
                if (a[i] == b[i])
                    cout << a[i];
                else{
                    if (count > 0){
                        if (flag)
                            cout << a[i];
                        else
                            cout << b[i];
                        flag = !flag;
                        count--;
                    }else{
                        char diff = ((a[i] + 1 - 'a') % 26) + 'a';
                        if (diff == b[i])
                            diff = (diff + 1 - 'a') % 26 + 'a';
                        cout << diff;
                    }
                }
            }
        }
    }

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}