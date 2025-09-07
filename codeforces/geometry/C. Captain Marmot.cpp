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

void rotate(pair<Point,Point> &p){
    Point newP = p.first - p.second; // let home = (0,0)
    newP = {-newP.y, newP.x}; // rotate

    p.first = newP + p.second;
}

int calcDistSq(Point p1, Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

bool valid(vector<Point> p){
    int l = oo;
    FOR(i,0,4)
        FOR(j,i + 1,4)
            l = min(l, calcDistSq(p[i],p[j]));

    FOR(i,0,4){
        int cnt1 = 0, cnt2 = 0;
        FOR(j,0,4)
            if (calcDistSq(p[i],p[j]) == l)
                cnt1++;
            else if (calcDistSq(p[i],p[j]) == 2*l)
                cnt2++;

        if (cnt1 != 2 || cnt2 != 1)
            return false;
    }

    return true;
}

void solve(){
    int n; cin >> n;  //x y  home 
    vector<vector<pair<Point,Point>>> p(n, vector<pair<Point,Point>>(4));
    FOR(i,0,n)
        FOR(j,0,4)
            cin >> p[i][j].first.x >> p[i][j].first.y >> p[i][j].second.x >> p[i][j].second.y;

    FOR(i,0,n){
        vector<vector<pair<int,Point>>> perm(4);
        FOR(j,0,4)
            FOR(k,0,4){
                perm[j].push_back({k,p[i][j].first});
                rotate(p[i][j]);
            }
        int res = oo;
        FOR(a1,0,4)
        FOR(a2,0,4)
        FOR(a3,0,4)
        FOR(a4,0,4){
            int c = perm[0][a1].first + perm[1][a2].first + perm[2][a3].first + perm[3][a4].first;
            vector<Point> arr = {
                perm[0][a1].second,
                perm[1][a2].second,
                perm[2][a3].second,
                perm[3][a4].second,
            };
            if (valid(arr))
                res = min(res,c);
        }

        if (res == oo)
            cout << -1 << endl;
        else 
            cout << res << endl;
    }
        
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}