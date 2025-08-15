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
    int x,y, dist, id;
    Point(){
        x = -1;
        y = -1;
        dist = 0;
        id = -1;
    }
    Point(int first, int second, int d){
        x = first;
        y = second;
        dist = d;
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

int calcDistSquared(Point p1, Point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

static bool cmp(Point p1, Point p2){
    return p1.dist < p2.dist;
}

pair<int,int> getSlope(Point p1, Point p2){
    int dy = p1.y - p2.y, dx = p1.x - p2.x;
    int g = gcd(dy,dx);
    dy /= g; dx /= g;

    if (dx < 0)
        dy = -dy, dx = -dx;

    if (dx == 0 && dy != 0)
        dy /= dy;
    if (dx != 0 && dy == 0)
        dx /= dx;

    return {dy,dx};
}

void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n){
        cin >> p[i].x >> p[i].y;
        p[i].id = i + 1;
    }

    FOR(i,1,n)
        p[i].dist = calcDistSquared(p[0],p[i]);

    sort(all(p), cmp);

    cout << p[0].id << " ";
    cout << p[1].id << " ";

    pair<int,int> slope = getSlope(p[0], p[1]);
  

    FOR(i,2,n){
        if (getSlope(p[0],p[i]) != slope){
            cout << p[i].id << " ";
            return;
        }
    }
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}