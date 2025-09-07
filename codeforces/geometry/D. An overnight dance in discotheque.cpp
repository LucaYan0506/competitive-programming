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

struct Circle{
    int x,y,r,level;
    Circle(){
        x = 0;
        y = 0;
        r = 0;
        level = 0;
    }
};
static bool cmp(Circle c1, Circle c2){
    return c1.r > c2.r;
}
int distSq(int x1, int y1, int x2, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 -y2) * (y1 - y2);
}

bool inside(Circle big, Circle small){
    int a = distSq(big.x, big.y, small.x, small.y);
    return distSq(big.x, big.y, small.x, small.y) <= big.r * big.r;
}

void solve(){
    int n; cin >> n;
    vector<Circle> c(n);
    FOR(i,0,n)
        cin >> c[i].x >> c[i].y >> c[i].r;
    sort(all(c), cmp);

    FOR(i,1,n){
        FORI(j,i-1,-1){
            if (inside(c[j],c[i])){
                c[i].level = c[j].level + 1;
                break;
            }
        }
    }

    vector<int> cnt(n+1); // cnt[i] means tot_area/PI of level i
    FOR(i,0,n)
        cnt[c[i].level] += c[i].r * c[i].r;

    // dp[i][0]=val ,dp[i][1]=sign for first half, dp[i][2] sign for second half
    vector<vector<int>> dp0(n, vector<int>(3)); 
    vector<vector<int>> dp1(n, vector<int>(3)); 
    dp0[0] = {cnt[0],1,-1};
    dp1[0] = {cnt[0],-1,1};

    FOR(i,1,n){
        int a = dp0[i-1][0] + cnt[i] * dp0[i-1][2];
        int b = dp1[i-1][0] + cnt[i] * dp1[i-1][2];
        if (a>b)
            dp0[i] = {a, dp0[i-1][1], dp0[i-1][2] * -1};
        else
            dp0[i] = {b, dp1[i-1][1], dp1[i-1][2] * -1};


        a = dp0[i-1][0] + cnt[i] * dp0[i-1][1];
        b = dp1[i-1][0] + cnt[i] * dp1[i-1][1];
        if (a>b)
            dp0[i] = {a, dp0[i-1][1] * -1, dp0[i-1][2]};
        else
            dp0[i] = {b, dp1[i-1][1] * -1, dp1[i-1][2]};
    }

    const double PI = acos(-1);
    cout << setprecision(20);
    cout << max(dp0[n-1][0], dp1[n-1][0]) * PI << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}