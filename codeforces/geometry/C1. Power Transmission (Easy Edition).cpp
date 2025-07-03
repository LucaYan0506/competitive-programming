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

struct Gradient {
    int num; 
    int den; 

    Gradient(int numerator, int denominator) : num(numerator), den(denominator) {
        normalize();
    }

    void normalize() {
        if (den < 0) { 
            den = -den;
            num = -num;
        }
        int g = gcd(num, den);
        if (g != 0) {
            num /= g;
            den /= g;
        }

    }
};

bool operator<(const Gradient& lhs, const Gradient& rhs) {
    if (lhs.num != rhs.num) return lhs.num < rhs.num;
    return lhs.den < rhs.den;
}

bool operator==(const Gradient& lhs, const Gradient& rhs) {
    return lhs.num == rhs.num && lhs.den == rhs.den;
}

void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n)
        cin >> p[i].x >> p[i].y;

    map<Gradient,vector<Point>> cnt;
    FOR(i,0,n)
        FOR(j,i + 1,n){
            Gradient temp = Gradient(p[i].y - p[j].y, p[i].x - p[j].x);
            bool unique = true;
            for (Point start : cnt[temp]){
                Gradient g = Gradient(p[i].y - start.y, p[i].x - start.x);
                if (g == temp || (g.den == temp.den && g.den == 0)){
                    unique = false;
                    break;
                }
                if (p[i] == start){
                    unique = false;
                    break;
                }
            }
            if (unique)
                cnt[temp].push_back(p[i]);

        }

    int k = 0;
    for(auto &[key,val] : cnt){
        k += val.size();
    }

    int res = k * (k - 1) / 2;

    for(auto &[key,val] : cnt){
        res -= val.size() * (val.size() - 1) / 2;
    }

    cout << res << endl;

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}