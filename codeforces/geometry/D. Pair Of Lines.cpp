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

pair<int,int> calcSlope(Point p1, Point p2){
    int dy = p1.y - p2.y;
    int dx = p1.x - p2.x;

    // special case
    if (dx == 0)
        dy /= dy;
    if (dy == 0)
        dx /= dx;

    int g = gcd(dy,dx);
    dy /= g;
    dx /= g;

    if (dx < 0)
        dy = -dy, dx = -dx;

    return {dy,dx};
}
void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

int findK(vector<Point> p, int i){
    map<pair<int,int>,int> cnt;
    int k = 0;
    FOR(j,0,p.size())
        if (i != j){
            auto slope = calcSlope(p[i],p[j]);
            cnt[slope]++;
        }
    
    for (auto [key,val] : cnt)
        if (val >= 2)
            k++;

    return k;
}

bool check(vector<Point> p, int i){
    if (p.size() <= 2)
        return true;

    int k = findK(p, i);
    
    if (k > 2)
        return false;
    if (k == 2){
        if (i > 0)
            return false;
        else 
            return check(p, 1);
    }
    if (k == 1){
        map<pair<int,int>,vector<int>> cnt;

        FOR(j,0,p.size())
            if (i != j){
                pair<int,int> slope = calcSlope(p[i],p[j]);
                cnt[slope].push_back(j);
            }
        vector<Point> newP;
        for (auto [key,val] : cnt){
            if (val.size() == 1)
                newP.push_back(p[val[0]]);
        }

        if (newP.size() <= 2)
            return true;
        
        auto slope = calcSlope(newP[0],newP[1]);
        FOR(j,2,newP.size()){
            auto curr = calcSlope(newP[0],newP[j]);
            if (slope != curr)
                return false;
        }
        
        return true;
    }
    if (k == 0){
        if (i < 2)
            return check(p,i + 1);
        else
            return false;
    }

    // impossible to reach
    return false;
}

void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n)
        cin >> p[i].x >> p[i].y;

    if (n <= 4 || check(p, 0))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}