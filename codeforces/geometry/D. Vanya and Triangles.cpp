#include<bits/stdc++.h>

// #define int long long 
// #define double long double 
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

tuple<int,int,int> getLine(Point p1, Point p2){
    // line: ax+by+c=0 -> dy*x + dx*y + c = 0
    int dy = p1.y - p2.y, dx = p1.x - p2.x;
    if (dx < 0)
        dy = -dy, dx = -dx;
    int c = -dy*p1.x - dx*p1.y;

    int g = gcd(dy,dx); g = gcd(g,c);
    dy /= g; dx /= g; c /= g;

    return make_tuple(dy,dx,c);
}

void solve1(){
    int n; cin >> n;
    vector<Point> p(n);
    
    FOR(i,0,n)
        cin >> p[i].x >> p[i].y;

    map<tuple<int,int,int>, set<int>> groupP;

    FOR(i,0,n)
        FOR(j,i + 1, n){
            tuple<int,int,int> line = getLine(p[i],p[j]);
            groupP[line].insert(i);
            groupP[line].insert(j);
        }

    int res = n*(n-1)*(n-2)/6;
    for (auto const [key,val] : groupP){
        int l = val.size();
        res -= l*(l-1)*(l-2)/6;
    }
    cout << res << endl;
}

int x[2000],y[2000],res,n;
void solve(){
	cin >> n;
	FOR(i,0,n)
        cin >> x[i] >> y[i];
	FOR(i,0,n)
        FOR(j,i + 1, n)
            FOR(k, j + 1, n)
		        if((y[i] - y[j]) * (x[i] - x[k]) != (y[i] - y[k]) * (x[i] - x[j]))res++;
	
    cout<< res << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}