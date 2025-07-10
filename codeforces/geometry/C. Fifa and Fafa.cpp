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
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

struct Point{
    double x,y;
    Point(){
        x = -1;
        y = -1;
    }
    Point(double first, double second){
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

struct Circle{
    int r;
    Point center;
    Circle(){
        r = -1;
        center = Point();
    }

    Circle(int _r, Point _c){
        r = _r;
        center = _c;
    }
};


struct Line{
    //y = mx + c
    double m,c;
    Line(){
        m = -1;
        c = -1;
    }

    Line(double _m, double _c){
        m = _m;
        c = _c;
    }
};

double calcDist(Point p1, Point p2){
    return sqrtl((double)(p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

Line findLine(Point p1, Point p2){
    double m = (double)(p1.y - p2.y) / (double)(p1.x - p2.x);
    double c = p1.y - m*p1.x;

    return Line(m,c);
}

Point getP1(int r, Line l, pair<int,int> dir, Point center){
    double m = l.m, c = l.c;

    double x = (-2*c*m + sqrtl(4*c*c*m*m-4*(m*m+1)*(c*c-r*r))) / (double)((m*m+1) * 2);
    x = abs(x);
    double y = m*x + c;

    return Point(center.x + x*dir.first, center.y+y*dir.second);
}

void solve(){
    Circle flat; cin >> flat.r >> flat.center.x >> flat.center.y;
    Point laptop; cin >> laptop.x >> laptop.y;

    //laptop outside
    if (calcDist(flat.center, laptop) >= flat.r){
        cout << flat.center.x << " " << flat.center.y << " " << flat.r << endl;
        return;
    }

    if (flat.center == laptop){
        cout << flat.center.x + flat.r / 2.0  << " " << flat.center.y << " " << flat.r / 2.0 << endl;
        return;
    }

    pair<int,int> dir = {
        flat.center.x - laptop.x,
        flat.center.y - laptop.y,
    };

    if (dir.first != 0)
        dir.first = dir.first / abs(dir.first);
    if (dir.second != 0)
        dir.second = dir.second / abs(dir.second);

    if (flat.center.x == laptop.x){
        double dist = abs(calcDist(flat.center,laptop)) + flat.r;
        dist = dist / 2.0;
        cout << laptop.x << " " << laptop.y + dist * dir.second << " " << dist << endl;
        return;
    }

    if (flat.center.y == laptop.y){
        double dist = abs(calcDist(flat.center,laptop)) + flat.r;
        dist = dist / 2.0;
        cout << laptop.x + dist * dir.first << " " << laptop.y << " " << dist << endl;
        return;
    }

    double r1 = abs(calcDist(flat.center, laptop));
    double r2 = r1 + flat.r;
    double x1 = abs(flat.center.x - laptop.x);
    double y1 = abs(flat.center.y - laptop.y);

    cout << setprecision(20);
    cout << laptop.x + r2/r1*x1/2.0*dir.first << " " << laptop.y + r2/r1*y1/2.0*dir.second << " " <<  r2/2.0;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}