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

// random_device dev;
// mt19937 rng(dev());
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

struct Point{
    int x;
    double y;
    Point(){
        x = -1;
        y = -1;
    }
    Point(int first, double second){
        x = first;
        y = second;
    }
};

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

double calcY(int h, int c1){
    return sqrtl(h*h - c1*c1);
}

void solve(){
    int n,r; cin >> n >> r;
    vector<int> x(n);
    FOR(i,0,n)
        cin >> x[i];

    vector<Point> p;
    cout << setprecision(15);
    FOR(i,0,n){
        vector<int> occupied;

        FOR(j,0, p.size())
            if (abs(x[i]-p[j].x) <= 2*r){
                // if (occupied == -1)
                    // occupied = j;       
                // else if (p[occupied].y < p[j].y)
                    // occupied = j;    
                occupied.push_back(j);   
            }


        if (occupied.size() == 0){
            cout << r << " ";
            p.push_back(Point(x[i],r));
        }else{
            double y = 0;
            FOR(j,0,occupied.size())
                y = max(p[occupied[j]].y + calcY(2*r,abs(x[i]-p[occupied[j]].x)), y);
            cout << y << " ";
            p.push_back(Point(x[i],y));
        }
    }
    cout << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}