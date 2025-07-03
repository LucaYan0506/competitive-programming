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
        return x == other.x && y < other.y;
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

bool inRange(double start, double end, double x){
    if (start > end)
        return inRange(end, start, x);
    
    return start <= x && x <= end;
}

bool isValid(Point A, Point B, Point p){
    bool res =  inRange(A.x, B.x, p.x) && inRange(A.y, B.y, p.y);
    return res;
}

double calcCartesianDist(Point p1, Point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double calcManhttanDist(Point p1, Point p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void solve(){
    int a,b,c; cin >> a >> b >> c;
    Point A,B; cin >> A.x >> A.y >> B.x >> B.y;
    double minDist = calcManhttanDist(A,B);
    vector<Point> points = {
        Point((-b*A.y - c)/a, A.y),
        Point(A.x, (-a*A.x - c)/b),
        Point(B.x, (-a*B.x - c)/b),
        Point((-b*B.y - c)/a, B.y),
    };
    set<Point> validPSet;
    vector<Point> validP;
    for (auto p : points)
        if (isValid(A,B,p))
            validPSet.insert(p);

    for (auto p : validPSet)
        validP.push_back(p);
    cout.precision(16);
    if (validP.size() < 2){
        cout << minDist << endl;
        return;
    }   

    minDist = min(minDist, calcManhttanDist(A,validP[0]) + calcCartesianDist(validP[0], validP[1]) + calcManhttanDist(validP[1], B));
    minDist = min(minDist, calcManhttanDist(A,validP[1]) + calcCartesianDist(validP[0], validP[1]) + calcManhttanDist(validP[0], B));
 
    cout << minDist << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}