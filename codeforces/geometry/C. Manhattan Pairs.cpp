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

random_device dev;
mt19937 rng(dev());
int get_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

struct Point{
    int x,y, id;
    Point(){
        x = -1;
        y = -1;
        id = -1;
    }
    Point(int first, int second){
        x = first;
        y = second;
    }

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

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

static bool cmp1(Point& p1, Point p2){
    return p1.x < p2.x;
}

static bool cmp2(Point& p1, Point p2){
    return p1.y < p2.y;
}

static bool cmp3(Point& p1, Point p2){
    return p1.y > p2.y;
}

void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n){
        cin >> p[i].x >> p[i].y;
        p[i].id = i + 1;
    }
    
    sort(all(p), cmp1); //sort by x

    vector<Point> p1(n/2), p2(n/2);
    FOR(i,0,n / 2)
        p1[i] = p[i],
        p2[i] = p[i + n/2];

    sort(all(p1), cmp2); //ascending by y
    sort(all(p2), cmp3); //descending by y

    int res = 0;
    FOR(i,0,n/2)
        cout << p1[i].id << " " << p2[i].id << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}