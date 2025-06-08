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
    FOR(i,0,n)
        cin >> a[i];
    vector<vector<bool>> tables(448,vector<bool>(448,0));

    //                  y,x
    pair<int,int> t0 = {0,0}; 
    //                y,x,k
    vector<int> t1 = {0,0,0}; 
    for (int t : a){
        if (t == 0){
            //update t0
            while(tables[t0.first][t0.second] == 1){
                if (t0.first == 0){
                    int originY =  t0.first + 2;
                    for (int y = t0.first + 2; y >= 0; y -= 2){
                        int x = originY - y;
                        t0 = {y,x};
                        if (tables[y][x] == 0)
                            break;
                    }
                }else{
                    t0 = {t0.first - 2,t0.second + 2};
                }
            }

            tables[t0.first][t0.second] = 1;

            //print x,y
            cout << (t0.second / 2) * 3 + 1 << " " << (t0.first / 2) * 3 + 1 << endl;


        }else{
            //update t1
            while (tables[t1[0]][t1[1]] == 1){
                if (t1[0] == 0 && t1[1] % 2 == 1){
                    auto originY = t1[0] + 2;
                    for (int y = t1[0] + 2; y >= 0; y -= 2){
                        int x = originY - y;
                        t1 = {y,x,-1};
                        if (tables[y][x] == 0)
                            break;
                    }
                }else if (t1[0] == 0 && t1[1] % 2 == 0){
                    int k = 0;
                    auto originY = t1[1] + 1;
                    for (int y = t1[1] + 1; y >= 0; y--){
                        int x = originY - y;
                        k++;
                        t1 = {y,x,k};
                        if (tables[y][x] == 0)
                            break;
                        
                        if (k % 2 == 0 && y > 0){
                            int newY = y - 1;
                            if (tables[newY][x] == 0){
                                t1 = {newY,x,0};
                                break;
                            }
                        }
                    }
                }else{
                    if (t1[2] == -1)
                        t1 = {t1[0] - 2,t1[1] + 2,-1};
                    else if (t1[2] == -2)
                        t1 = {t1[0],t1[1] + 1,0};
                    else if (t1[2] % 2 == 0)
                        t1 = {t1[0] - 1,t1[1],-2};
                    else if (t1[2] % 2 == 1)
                        t1 = {t1[0] - 1,t1[1] + 1,0};
                }
            }


            tables[t1[0]][t1[1]] = 1;
            //print x,y
            cout << (t1[1] / 2) * 3 + 1 + (t1[1] % 2) << " " << (t1[0] / 2) * 3 + 1 + (t1[0] % 2) << endl;

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