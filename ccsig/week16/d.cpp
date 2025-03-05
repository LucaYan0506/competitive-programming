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
    vector<int> a;
    int totA = 0;
    vector<int> b;
    int totB = 0;
    int lastMove = 0; // 0 positive, 1 negative
    FOR(i,0,n){
        int temp; cin >> temp;
        if (temp > 0){
            a.push_back(temp);
            totA += temp;
            lastMove = 0;
        }
        else{
            b.push_back(temp);
            totB += abs(temp);
            lastMove = 1;
        }
    }

    if (totA > totB)
        cout << "first" << endl;
    else if (totA < totB)
        cout << "second" << endl;
    else{
        FOR(i,0,min(a.size(),b.size())){
            if (a[i] > abs(b[i])){
                cout << "first" << endl;
                return;
            }else if (a[i] < abs(b[i])){
                cout << "second" << endl;
                return;
            }
        }

        if (a.size() > b.size())
            cout << "first" << endl;
        else if (a.size() < b.size())
            cout << "second" << endl;   
        else {
            if (lastMove == 0)
                cout << "first" << endl;
            else
                cout << "second" << endl;
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