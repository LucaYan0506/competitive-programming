#include<bits/stdc++.h>

#define int long long 
#define double long double 
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

    Point& operator-=(const Point& other) {
        x -= other.x;
        y -= other.y;
        return *this;
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

int calcDistSqr(Point p1, Point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

double calcDistLineToOrigin(Point p1, Point p2){
    // ax + by + c = 0;
    int a = -(p1.y - p2.y), b = p1.x - p2.x, c = - a*p1.x - p1.y*b;
    double intersectionX = 0; // if a = 0, it intersect at x = 0
    if (a != 0)
        intersectionX = (-a*c*1.0) / (a*a + b*b);
    if (intersectionX < min(p1.x, p2.x) || intersectionX > max(p1.x, p2.x))
        return oo;
    return abs(c) / sqrtl(a*a + b*b);
}

void solve(){
    int n; cin >> n;
    Point p; cin >> p.x >> p.y;
    vector<Point> v(n);
    FOR(i,0,n)
        cin >> v[i].x >> v[i].y;

    int maxi = -oo;
    double mini = oo;

    FOR(i,0,n){
        v[i] -= p;
        maxi = max(maxi, calcDistSqr(Point(0,0), v[i]));
        mini = min(mini, sqrtl(calcDistSqr(Point(0,0), v[i])));
    }

    FOR(i,0,n){
        double d = calcDistLineToOrigin(v[i],v[(i+1) % n]);
        mini = min(mini,d);
    }

    const double PI = atan2(0,-1);
    double res = maxi * PI - mini * mini * PI;
    cout << setprecision(16);
    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}