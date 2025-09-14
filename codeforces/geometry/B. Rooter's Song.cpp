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


/*
/////////////////////////////////////////
//////////////// too slow ///////////////
/////////////////////////////////////////
struct CustomPoint{
    int index;
    int p;
    int g; // 1 or 2
    int t;
    bool solved;
    CustomPoint(){

    }
};

static bool cmp(CustomPoint& a, CustomPoint& b){
    return a.p > b.p;
}
void solve(){
    int n,w,h; cin >> n >> w >> h;
    vector<CustomPoint> p(n);
    map<int, vector<CustomPoint>> m1,m2;
    FOR(i,0,n){
        cin >> p[i].g;
        cin >> p[i].p;
        cin >> p[i].t;
        p[i].index = i;
    }

    sort(all(p),cmp);
    FOR(i,0,n)
        if (p[i].g == 1)
            m1[p[i].p - p[i].t].push_back(p[i]);
        else
            m2[p[i].p - p[i].t].push_back(p[i]);

    vector<Point> res(n);
    for(auto &[key,val] : m1){
        while(!val.empty()){
            CustomPoint curr = val.back();
            Point destination = Point(curr.p, h);
            if (curr.g == 2)
                destination = Point(w, curr.p);

            //if collide
            if (m2.count(key) && m2[key].size() > 0){
                auto& m2Value = m2[key];
                FORI(i,m2Value.size() - 1, -1){
                    CustomPoint &collideP = m2Value[i];
                    swap(curr.index, collideP.index);
                }
            }

            val.pop_back();
            res[curr.index] = destination;
        }
    }

    for(auto &[key,val] : m2){
        while(!val.empty()){
            CustomPoint curr = val.back();
            Point destination = Point(curr.p, h);
            if (curr.g == 2)
                destination = Point(w, curr.p); 

            val.pop_back();
            res[curr.index] = destination;
        }
    }

    FOR(i,0,n)
        cout << res[i].x << " " << res[i].y << endl;
}
*/

struct CustomPoint{
    int index;
    int x,y;
    int t,g;

    CustomPoint(){
        x = 0; y = 0;
        index = -1;
        t = 0;
    }

    CustomPoint(int first, int second){
        x = first;
        y = second;
    }
};

static bool cmp(CustomPoint p1, CustomPoint p2){
    if (p1.g != p2.g) return p1.g < p2.g;
    if (p1.g == 1) return p1.x > p2.x;
    return p1.y < p2.y;
}

static bool cmp2(CustomPoint p1, CustomPoint p2){
    return p1.y - p1.x < p2.y - p2.x;
}


void solve(){
    int n,w,h; cin >> n >> w >> h;
    // vector<CustomPoint> p(n);
    map<int, vector<CustomPoint>> m;
    FOR(i,0,n){
        CustomPoint p;
        cin >> p.g;
        if (p.g == 1)
            cin >> p.x;
        else
            cin >> p.y;

        cin >> p.t;
        p.index = i;
        m[p.x + p.y - p.t].push_back(p);
    }

    vector<CustomPoint> res(n);
    for (auto &[key,val] : m){
        vector<CustomPoint> exits;
        for (auto p : val)
            if (p.x == 0)
                exits.push_back(CustomPoint(w, p.y));
            else
                exits.push_back(CustomPoint(p.x, h));

            sort(all(val),cmp);
            sort(all(exits), cmp2);

        FOR(i,0,val.size())
            res[val[i].index] = exits[i];
    }

    FOR(i,0,n)
        cout << res[i].x << " " << res[i].y << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}