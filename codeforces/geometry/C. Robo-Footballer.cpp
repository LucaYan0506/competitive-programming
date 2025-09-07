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

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
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
const double PI = acos(-1);
double custom_y1,custom_y2,yw,xb,yb,radius; 
double calcY(double x){
    double theta = atan2(xb-x,yw-yb-radius);

    if (yw - custom_y2 - radius > 0){
        double k = sqrtl(x*x + (yw-custom_y2-radius)*(yw-custom_y2-radius));
        double alpha = acos(x/k);
        // return x * (yw - custom_y2 - radius) / k + sinl(theta)*cosl(theta);
        return k * sinl(PI/2-theta-alpha);
    }


    double o = radius- (yw -custom_y2), h = sqrtl(o*o+x*x);
    double alpha = atan2(o,x), beta = theta-alpha;
    return h*cosl(beta);
}

double calcY2(double x){
    double y = x * (yw-yb - radius) / (xb-x);
    return yw - y - radius;
}

void solve(){
    cin >> custom_y1 >> custom_y2 >> yw >> xb >> yb >> radius;

    double l = 0, r = xb, res = -1;
    FOR(i,0,50){
        double m1 = l + (r-l)/3., m2 = m1 + (r-l)/3.;
        

        double firstY = abs(calcY(m1)); //distance between line at theta degree and y2

        double firstY1 =calcY2(m1); // consider the center of the ball at (x,y1)
        double secondY1 =calcY2(m2);
         if (secondY1 - radius <= custom_y1 || firstY1 - radius <= custom_y1)
            r = m2;
        else if(firstY <= radius || firstY1 + radius >= custom_y2)
            l = m1;
        else{
            res = (m2+m1)/2;
            break;
        }
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