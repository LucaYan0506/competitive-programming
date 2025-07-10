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

struct Square{
    Point p1,p2,p3,p4;

    Square(){
        p1 = Point();
        p2 = Point();
        p3 = Point();
        p4 = Point();
    }

    Square(Point _p1, Point _p2, Point _p3, Point _p4){
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
        p4 = _p4;
    }

    void rotate(){
        auto temp = p1;
        p1 = p2;
        p2 = p3;
        p3 = p4;
        p4 = temp;
    }
};

bool inRange(int start, int end, int val){
    if (start > end)
        return inRange(end, start, val);
    
    return start <= val && val <= end;
}

bool isValid(Square sqr1, int x, int y){
    return inRange(sqr1.p1.x, sqr1.p3.x, x) && inRange(sqr1.p2.y, sqr1.p4.y, y);
}

void solve(){
    Square sqr1, sqr2;
    cin >> sqr1.p1.x >> sqr1.p1.y >> sqr1.p2.x >> sqr1.p2.y >> sqr1.p3.x >> sqr1.p3.y >> sqr1.p4.x >> sqr1.p4.y;
    cin >> sqr2.p1.x >> sqr2.p1.y >> sqr2.p2.x >> sqr2.p2.y >> sqr2.p3.x >> sqr2.p3.y >> sqr2.p4.x >> sqr2.p4.y;

    if (sqr1.p1.x == sqr1.p3.x)
        sqr1.rotate();

    if (sqr2.p1.x == sqr2.p3.x)
        sqr2.rotate();

    int sqr2DiagonalLenght = abs(sqr2.p1.x - sqr2.p3.x);
    int top = max(sqr2.p2.y, sqr2.p4.y);
    int bottom = min(sqr2.p2.y, sqr2.p4.y);

    FOR(y,0, sqr2DiagonalLenght / 2 + 1)
        FOR(x,-y,y + 1){
            if (isValid(sqr1, sqr2.p2.x + x,top - y)){
                cout << "YES" << endl;
                return;
            }

            if (isValid(sqr1, sqr2.p2.x + x,bottom + y)){
                cout << "YES" << endl;
                return;
            }
        }
        
    cout << "NO" << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}