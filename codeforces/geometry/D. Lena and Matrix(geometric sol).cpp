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
    int i,j;
    Point(){
        i = -1;
        j = -1;
    }
    Point(int first, int second){
        i = first;
        j = second;
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

int manhattan(const Point& a, const Point& b) {
    return abs(a.i - b.i) + abs(a.j - b.j);
};
pair<Point, Point> farthestManhattanPair(const vector<Point>& points) {

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
    int n,m; cin >> n >> m;
    vector<pair<Point,int>> points = {
        {Point(0,0),oo}, //min sum
        {Point(0,0),oo}, // min diff
        {Point(0,0),-oo}, // max diff
        {Point(0,0),-oo}, // max sum
    };
    FOR(i,0,n){
        string temp; cin >> temp;
        FOR(j,0,temp.size())
            if (temp[j] == 'B'){
                int sum = i + j;
                int diff = i - j;
                if (sum < points[0].second)
                    points[0] = {Point(i + 1, j + 1), sum};
                if (diff < points[1].second)
                    points[1] = {Point(i + 1, j + 1), diff};
                if (diff > points[2].second)
                    points[2] = {Point(i + 1, j + 1), diff};
                if (sum > points[3].second)
                    points[3] = {Point(i + 1, j + 1), sum};
            }
    }

    int minDist = oo;
    Point res;
    FOR(i,0,n)
        FOR(j,0,m){
            int maxDist = -oo;
            Point p1 = Point(i + 1,j + 1);
            for(auto &[p2,val] : points)
                maxDist = max(maxDist, manhattan(p1,p2));

            if (maxDist < minDist){
                minDist = maxDist;
                res = p1;
            }
        }
        
    cout << res.i << " " << res.j << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}