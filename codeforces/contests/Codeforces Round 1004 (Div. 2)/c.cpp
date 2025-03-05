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
    int n; cin >> n;
    vector<int> temp; //9, 99, 999..
    vector<int> temp2; //10, 100, 100..
    int baseCase = 9;
    int baseCase2 = 10;
    FOR(i,0,15){
        temp.push_back(baseCase);
        temp2.push_back(baseCase2);
        baseCase2 = baseCase2 * 10;
        baseCase = baseCase * 10 + 9;
    }


    vector<int> res;
    int d = 0;
    vector<int> digits;
    while(n > 0){
        int unitDigit = n % 10; 
        digits.push_back(unitDigit);
        n /= 10;
    }

    int currVal = 0;
    FOR(i,0,digits.size()){
        currVal = currVal + digits[i] * temp2[i]/10;

        FOR(j,0,i + 1){
            FOR(k,0,10){
                FOR(l,0,temp2.size()){
                    if ((temp[j] * k + currVal) % temp2[l] >= (7 * temp2[l]/10)
                        && (temp[j] * k + currVal) % temp2[l] < (8 * temp2[l]/10)){
                        res.push_back(k);
                        break;
                    };
                }
            }
        }        
    }


    sort(all(res));
    cout << res[0] << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}