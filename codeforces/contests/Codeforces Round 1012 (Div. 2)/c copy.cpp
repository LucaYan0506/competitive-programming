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
    vector<vector<vector<bool>>> tables(225,vector<vector<bool>>(225,vector<bool>(4,0)));

    //                  y,x
    pair<int,int> t0 = {0,0};
    //                y,x, count 
    vector<int> t1 = {0,0,0}; 
    for (int t : a){
        if (t == 0){
            tables[t0.first][t0.second][0] = 1;
            //print x,y
            cout << t0.second * 3 + 1 << t0.first * 3 + 1 << endl;

            //update t0
            while(tables[t0.first][t0.second][0] != 0){
                if (t0.first == 0){
                    FORI(y,t0.first + 1,-1){
                        int x = (t0.first + 1) - y;
                        t0 = {y,x};
                        if (tables[y][x][0] == 0)
                            break;
                    }
                }else
                    t0 = {t0.first - 1,t0.second + 1};
            }

        }else{
            tables[t1[0]][t1[1]][t1[2]] = 1;
            //print x,y
            cout << t1[1] * 3 + 1 << t1[0] * 3 + 1 << endl;

            //update t1
            while (tables[t1[0]][t1[1]][t1[2]] == 1){
                if (t1[0] == 0){
                    FORI(y,t1[0] + 1,-1){
                        int x = (t1[0] + 1) - y;
                        t1 = {y,x};
                        if (tables[y][x] == 1){
                            break;
                        }
                    }
                }else{
                    t1 = {t1.first - 1,t1.second + 1};
                }
            }
        }
    }
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}