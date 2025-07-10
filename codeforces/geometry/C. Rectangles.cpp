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

    bool operator!=(const Point& other) const {
        return x != other.x || y != other.y;
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

bool isValid(pair<Point,Point> &rec1, pair<Point,Point> &rec2){
    if (rec2.first.x > rec1.second.x || rec2.first.y > rec1.second.y || rec2.second.x < rec1.first.x || rec2.second.y < rec1.first.y)
        return false;
    return true;
}

void updateValidRange(pair<Point,Point> &rec1, pair<Point,Point> &rec2){
    rec1.first.x = max(rec1.first.x,rec2.first.x);
    rec1.first.y = max(rec1.first.y,rec2.first.y);

    rec1.second.x = min(rec1.second.x,rec2.second.x);
    rec1.second.y = min(rec1.second.y,rec2.second.y);
}

void solve(){
    int n; cin >> n;
    vector<pair<Point,Point>> rec(n);
    FOR(i,0,n)
        cin >> rec[i].first.x >> rec[i].first.y >> rec[i].second.x >> rec[i].second.y;

    vector<pair<Point,Point>> validRangePreffix(n); 
    vector<pair<Point,Point>> validRangeSuffix(n); 
    validRangePreffix[0] = rec[0];
    validRangeSuffix[n - 1] = rec[n - 1];
    FOR(i,1,n)
        if (isValid(validRangePreffix[i - 1], rec[i])){
            validRangePreffix[i] = validRangePreffix[i - 1];
            updateValidRange(validRangePreffix[i], rec[i]);
        }
        else
            validRangePreffix[i] = {Point(1e11,1e11), Point(1e11,1e11)};

    FORI(i,n - 2,-1)
        if (isValid(validRangeSuffix[i + 1], rec[i])){
            validRangeSuffix[i] = validRangeSuffix[i + 1];
            updateValidRange(validRangeSuffix[i], rec[i]);
        }
        else
            validRangeSuffix[i] = {Point(1e11,1e11), Point(1e11,1e11)};

    if (validRangeSuffix[1].first != Point(1e11,1e11)){
        cout << validRangeSuffix[1].first.x << " " << validRangeSuffix[1].first.y << endl;
        return;
    }

    if (validRangePreffix[n - 2].first != Point(1e11,1e11)){
        cout << validRangePreffix[n - 2].first.x << " " << validRangePreffix[n - 2].first.y << endl;
        return;
    }

    FOR(i,0, n - 2){
        if (isValid(validRangePreffix[i], validRangeSuffix[i + 2])){
            auto res = validRangePreffix[i];
            updateValidRange(res, validRangeSuffix[i + 2]);
            cout << res.first.x << " " << res.first.y << endl;
            
            return;
        }

        if (isValid(validRangeSuffix[i + 2], validRangePreffix[i])){
            auto res = validRangeSuffix[i + 2];
            updateValidRange(res, validRangePreffix[i]);
            cout << res.first.x << " " << res.first.y << endl;
            
            return;
        }
    }

    //shouldn't reach here
    cout << "my code is broken" << endl;

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}