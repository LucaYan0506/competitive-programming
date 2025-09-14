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
    int x,y;
    Point(){
        x = -1;
        y = -1;
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

pair<Point, Point> farthestManhattanPair(const vector<Point>& points) {
    auto manhattan = [](const Point& a, const Point& b) {
        return abs(a.x - b.x) + abs(a.y - b.y);
    };

    pair<Point, Point> bestPair = make_pair(Point(0, 0), Point(0, 0));
    int maxDistance = -1;

    // List of 4 transformations
    vector<pair<int, int>> directions = {
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}
    };

    for (auto [dx, dy] : directions) {
        int maxVal = INT_MIN, minVal = INT_MAX;
        Point maxPoint, minPoint;

        for (const auto& [x, y] : points) {
            int val = dx * x + dy * y;
            if (val > maxVal) {
                maxVal = val;
                maxPoint = {x, y};
            }
            if (val < minVal) {
                minVal = val;
                minPoint = {x, y};
            }
        }

        int dist = manhattan(maxPoint, minPoint);
        if (dist > maxDistance) {
            maxDistance = dist;
            bestPair = make_pair(minPoint, maxPoint);
        }
    }

    return bestPair;
}

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

struct Line{
    int a,b,c; // ax + by + c = 0;

    Line(){
        a = -1;
        b = -1;
        c = -1;
    }

    Line(int _a, int _b, int _c){
        a=_a;b=_b;c=_c;
        normalize();
    }

    Line(Point p1, Point p2){
        a = (p1.y - p2.y);
        b = - (p1.x - p2.x);
        c = -(a*p1.x + b*p1.y);
        normalize();
    }

    void normalize(){
        if (a < 0){
            a = -a;
            b = -b;
            c = -c;
        }

        int g = gcd(a,b); g = gcd(g,c);
        a /= g;
        b /= g;
        c /= g;
    }
};

double calcDist(Line l, Point p){
    return (double)abs(l.a*p.x + l.b*p.y + l.c) / (sqrtl(l.a*l.a + l.b*l.b));
}

void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n)
        cin >> p[i].x >> p[i].y;

    double res = oo;
    FOR(i,0,n)
        res = min(res, calcDist(Line(p[i],p[(i + 2) % n]), p[(i + 1) % n]) / 2.0);
  
    cout << setprecision(15);
    cout << res << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;while(t--)
        solve();

    return 0;
}