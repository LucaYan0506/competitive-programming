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

void findSol(int &x, int &y, int d, int n){
    if (d == 4){
        y += 1;
        return;
    }

    if (d == 3){
        x += 1;
        return;
    }

    if (d == 2){
        y += 1;
        x += 1;
        return;
    }

    if (d == 1)
        return;

    int q1 = (1 << n);
    int q2 = (1 << (n + 1));
    int q3 = (3 * (1 << n));
    int q4 = (1 << 2 + n);
    
    //4
    if (d <= q4 && d > q3){
        d -= q3;
        x += 0;
        y += n;
        return findSol(x,y,d,n - 2);
    }

    //3
    if (d <= q3 && d > q2){
        d -= q2;
        x += n;
        y += 0;
        return findSol(x,y,d,n - 2);
    }

    if (d <= q2 && d > q1){
        d -= q1;
        x += n;
        y += n;
        return findSol(x,y,d,n - 2);
    }

    return findSol(x,y,d,n - 2);
}

bool inRange(int n, int start, int end){
    return n >= start && n < end;
}

void findSol2(int x, int y, int &d, int n){
    if (n <= 1){
        if (x == 0 && y == 0)
            d++;
        else if (x == 1 && y == 1)
            d += 2;
        else if (x == 1 && y == 0)
            d += 3;
        else
            d += 4;
        return;
    }


    //1
    if (inRange(x,0,n) && inRange(y,0,n)){
        return findSol2(x,y,d,n - 1);
    }

    //2
    if (inRange(x,n,2 * n) && inRange(y,n,2*n)){
        d += (1 << n);
        x -= n;
        y -= n;
        return findSol2(x,y,d,n - 1);
    }

    //3
    if (inRange(x,n,2 * n) && inRange(y,0,n)){
        d += (1 << (n + 1));
        x -= n;
        y -= 0;
        return findSol2(x,y,d,n - 1);
    }

    //4
    if (inRange(x,0,n) && inRange(y,n,2*n)){
        d += 3 * (1 << n);
        x -= 0;
        y -= n;
        return findSol2(x,y,d,n - 1);
    }
}

void solve(){
    int n, q; cin >> n >> q;

    FOR(query,0,q){
        string cmd; cin >> cmd;

        if (cmd == "->"){
            int x,y; cin >> x >> y;
            x--,y--;
            int d = 0;
            findSol2(x,y,d,n);
            cout << d << endl;
        }else{
            int d; cin >> d;
            int x = 1,y = 1;
            findSol(x,y,d, 2*n);
            cout << x << " " << y << endl;            
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