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

void solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    int totAB = 0, totABsq = 0;

    FOR(i,0,n){
        cin >> a[i];
        totAB += a[i];
        totABsq += a[i]*a[i];
    }
    FOR(i,0,n){
        cin >> b[i],
        totAB += b[i];;
        totABsq += b[i]*b[i];
    }

    const int MAXTOT = 1e4 + 1;
    vector<vector<bool>> dp(n,vector<bool>(MAXTOT));
    dp[0][a[0]] = true;
    dp[0][b[0]] = true;

    FOR(i,1,n){
        FOR(j,0,MAXTOT){
            if (j - a[i] < 0 && j - b[i] < 0)
                continue;
            if (j - a[i] < 0)
                dp[i][j] = dp[i - 1][j - b[i]];
            else if (j - b[i] < 0)
                dp[i][j] = dp[i - 1][j - a[i]];
            else
                dp[i][j] = dp[i - 1][j - a[i]] || dp[i - 1][j - b[i]];
        }
    }

    int res = oo;
    FOR(j,0,MAXTOT)
        if (dp[n-1][j])
            res = min(res, j*j + (totAB-j)*(totAB-j));

    res += (n-2)*totABsq;
    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}