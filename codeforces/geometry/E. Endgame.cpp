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

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
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

bool withinBound(Point p, int n){
    return p.x >= 0 && p.x < n && p.y >= 0 && p.y < n;
}

bool canReach(Point p1, Point p2, vector<Point> &validM){
    set<Point> p1M,p2M,res;
    for(Point m : validM){
        Point newP = p1 + m;
        if (withinBound(newP, validM.size()))
            p1M.insert(newP);

        newP = p2 - m;
        if (withinBound(newP, validM.size()))
            p2M.insert(newP);  
    }

    if (p1M.find(p2) != p1M.end())
        return true;

    set_intersection(
        p1M.begin(), p1M.end(),
        p2M.begin(), p2M.end(),
        inserter(res, res.begin())
    );

    return res.size() != 0;
}

void solve(){
    int n; cin >> n;
    Point a,b; cin >> a.x >> a.y >> b.x >> b.y;
    a.x--;a.y--;b.x--;b.y--; //0-indexed
    vector<Point> validM(n);
    FOR(i,0,n)
        cin >> validM[i].x >> validM[i].y;
    
    //check if alice can win with bidirectinal search 
    if (canReach(a,b,validM)){
        cout << "Alice wins" << endl;
        return;
    }

    FOR(t,0,30){
        Point newP = Point(get_random(0,n-1), get_random(0,n-1));
        while (newP == b)
            newP = Point(get_random(0,n-1), get_random(0,n-1));
        if (!canReach(b,newP, validM)){
            cout << "tie " << newP.x + 1 << " " << newP.y + 1 << endl; 
            return;
        }
    }
    cout << "Bob wins" << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}