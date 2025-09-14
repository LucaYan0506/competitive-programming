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
const double eps = 1e-15;
const double PI = acos(-1);

using namespace std;

random_device dev;
mt19937 rng(dev());
int get_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

int customPow (int base, unsigned int exp){
    int res = 1;
    while (exp) {
        if (exp & 1)
            res *= base;
        exp >>= 1;
        base *= base;
    }
    return res;
}

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

    bool operator!=(const Point& other) const {
        return (x == other.x && y == other.y) == false;
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};

struct Line{
    int a,b,c; //ax+by+c=0
    Line(){
        a = -1;
        b = -1;
        c = -1;
    }

    //assuming p1 != p2
    Line(Point p1, Point p2){
        int dy = p1.y - p2.y,dx = p1.x - p2.x;
        
        //special case
        if (dy == 0)
            dx = 1;
        if (dx == 0)
            dy = 1;

        //normalize
        int g = gcd(dy,dx);
        dy /= g;
        dx /= g;
        if (dx < 0){
            dx = -dx;
            dy = -dy;
        }

        a = -dy;
        b = dx;
        c = -(p1.x*a + p1.y*b);
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

// determinant of cross product 
int detOfCrossProduct(Point origin, Point a, Point b){
    Point vec1 = a - origin, vec2 = b - origin;
    return vec1.x*vec2.y - vec1.y*vec2.x;
}

int dotProduct(Point OA, Point OB){
    return OA.x*OB.x + OA.y*OB.y;
}

double calcAngle(Point p, Point base = Point(0,0)){
    p = p - base;
    return atan2(p.y,p.x);
}

int calcDistSq(Point p1, Point p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

double calcDist(Line l, Point p){
    return fabs((l.a*p.x+l.b*p.y+l.c)/sqrtl(l.a*l.a+l.b*l.b));
}

vector<Point> graham_scan(vector<Point>&p){
    Point lowest_p = Point(0,oo);
    FOR(i,0,p.size())
        if (lowest_p.y > p[i].y || (p[i].y == lowest_p.y && p[i].x < lowest_p.x))
            lowest_p = p[i];

    vector<Point> newP;
    for (auto &x : p) 
        if (x != lowest_p)
            newP.push_back(x);


    //sort by counter-clockwise order
    sort(all(newP), [&lowest_p](const Point& a, const Point& b) {
        int o = detOfCrossProduct(lowest_p, a, b);

        // If points are collinear, keep the farthest one last
        if (o == 0) 
            return calcDistSq(lowest_p, a) < calcDistSq(lowest_p, b);

        return o > 0;
    });
    vector<Point> res;
    res.push_back(lowest_p);
    res.push_back(newP[0]);
    FOR(i,1,newP.size()){
        auto curr1 = res[res.size() - 2];
        auto curr2 = res.back();
        // use detOfCrossProduct(curr1, curr2, ang_dist[i].first) < 0 to **NOT** filter collinear points
        if (detOfCrossProduct(curr1, curr2, newP[i]) <= 0)
            res.pop_back(), i--;
        else
            res.push_back(newP[i]);
    }

    return res;
}

//calculate the normalized scalar projection of the vector OA onto OB
//assuming o a b are distict points
double normalizedScalarProjection(Point o, Point a, Point b){
    Point OA = a - o;
    Point OB = b - o; 
    return (double)dotProduct(OA,OB)/(OB.x*OB.x + OB.y*OB.y);
}

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n)
        cin >> p[i].x >> p[i].y;

    vector<Point> newP = graham_scan(p);
    double res = oo;
    FOR(i,0,newP.size()){
        Line l = Line(newP[i],newP[(i+1)%newP.size()]);
        double maxDist = -oo;
        FOR(j,0,newP.size()){
            if (newP[j] == newP[i] || newP[j] == newP[(i+1)%newP.size()])
                continue;

            //get dist between segment and newP
            double dist = calcDist(l,newP[j]);

            // if (normalizedScalarProjection(newP[i], newP[j],newP[(i+1)%newP.size()]) < 0 || normalizedScalarProjection(newP[i], newP[j],newP[(i+1)%newP.size()]) > 1)
            //     dist = min(sqrtl(calcDistSq(newP[i],newP[j])),sqrtl(calcDistSq(newP[(i+1)%newP.size()],newP[j])));

            maxDist = max(maxDist, dist);
        }

        res = min(res, maxDist);
    }

    cout << setprecision(20);
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