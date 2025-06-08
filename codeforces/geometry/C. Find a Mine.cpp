#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
#define oo 1000000000000000000ll

const int mod = 1e9+7;
using namespace std;

random_device dev;
mt19937 rng(dev());
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

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

// manathan distance from (1,1) to pos1
int calcDist(pair<int,int> pos1, int n, int m){
    if (pos1.second <= 0 || pos1.first <= 0)
        return -1;
    if (pos1.first > n || pos1.second > m)
        return INT_MAX;

    return abs(pos1.first - 1) + abs(pos1.second - 1);
}

pair<int,int> helper1(int firstD, int x, int y, int d, int n, int m, bool debug = false){
    int l = 0, r = d;
    while(l <= r){
        int mid = (l + r) / 2;
        int currDist = calcDist({x + d - mid, y - mid}, n, m);
        if (currDist < firstD)
            l = mid + 1;
        else if (currDist > firstD)
            r = mid - 1;
        else 
            return {x + d - mid, y - mid};
    }


    return {-1,-1};
}

pair<int,int> helper2(int firstD, int x, int y, int d, int n, int m, bool debug = false){
    int l = 0, r = d;
    while(l <= r){
        int mid = (l + r) / 2;
        int currDist = calcDist({x - d + mid, y + mid}, n, m);
        if (currDist < firstD)
            l = mid + 1;
        else if (currDist > firstD)
            r = mid - 1;
        else 
            return {x - d + mid, y + mid};
    }


    return {-1,-1};
}

void solve(){
    int n,m; cin >> n >> m;
    cout << "? " << 1 << " " << 1 << endl;
    int firstD; cin >> firstD;
    if (firstD == 0){
        cout << "! 1 1" << endl;
        return;
    }
    bool first = true;
    int x = max(1ll, firstD + 2 - m);
    int y = firstD + 2 - x;
    pair<int,int> firstPos = {x,y};
    x = min(n, firstD + 1);
    y = firstD + 2 - x;
    pair<int,int> lastPos = {x,y};

    vector<pair<int,int>> possibleRes;
    cout << "? " << firstPos.first << " " << firstPos.second << endl;
    int d;cin >> d;
    if (d == 0){
        cout << "! " << firstPos.first << " " << firstPos.second << endl;
        return;
    }
    auto temp = helper1(firstD, firstPos.first, firstPos.second, d, n, m);
    if (temp.first != -1)
        possibleRes.push_back(temp);
    cout << "? " << lastPos.first << " " << lastPos.second << endl;
    cin >> d;
    if (d == 0){
        cout << "! " << lastPos.first << " " << lastPos.second << endl;
        return; 
    }
    temp = helper2(firstD, lastPos.first, lastPos.second, d, n, m);
    if (temp.first != -1)
        possibleRes.push_back(temp);
    
    if (possibleRes.size() == 1)
        cout << "! " << possibleRes[0].first << " " << possibleRes[0].second << endl;
    else if (possibleRes.size() > 1){
        cout << "? " << possibleRes[0].first << " " << possibleRes[0].second << endl;
        cin >> d;
        if (d == 0)
            cout << "! " << possibleRes[0].first << " " << possibleRes[0].second << endl;
        else
            cout << "! " << possibleRes[1].first << " " << possibleRes[1].second << endl;
    }else
        cout << "ans not found" << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();


    // test
    // map<pair<int,int>,int> possiblePos;
    // helper(possiblePos, 1,1,3,4,4, true);

    return 0;
}