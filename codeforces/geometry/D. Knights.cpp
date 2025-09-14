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

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

int calcDist(Point p1, Point p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

struct Fence{
    Point center;
    int r;
    Fence(){
        center = Point();
        r = 0;
    }

    bool inside(Fence other){
        //if this inside other
        return calcDist(center, other.center) <= other.r*other.r;
    }
};

bool inside(Point p,Fence other){
    return calcDist(p, other.center) <= other.r*other.r;
    //if this inside other
}

static bool cmp(Fence a, Fence b){
    return a.r > b.r;
}

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<Point> p(n);
    vector<int> levels(m);
    vector<Fence> fence(m);
    FOR(i,0,n)
        cin >> p[i].x >> p[i].y;
    FOR(i,0,m)
        cin >> fence[i].r >> fence[i].center.x >> fence[i].center.y;
    
    sort(all(fence), cmp);
    vector<int> parentOf(m,-1);
    
    FORI(i,m-1,-1)
        FORI(j,i-1,-1)
            if (fence[i].inside(fence[j])){
                parentOf[i] = j;
                break;
            }
        
    vector<vector<int>> paths(m);
    // get path from curr to -1
    FOR(j,0,m){
        int curr = j;
        while(curr != -1){
            paths[j].push_back(curr);
            curr = parentOf[curr];
        }
    }

    FOR(i,0,k){
        int a,b; cin >> a >> b;
        a--,b--;
        vector<int> path1, path2;

        FORI(j,m-1,-1)
            if (inside(p[a],fence[j])){//if p[a] inside fence[j]
                path1 = paths[j];
                break;
            }
        FORI(j,m-1,-1)
            if (inside(p[b],fence[j])){
                path2 = paths[j];
                break;
            }
        
        while(path1.size() > 0 && path2.size() > 0 && path1.back() == path2.back())
            path1.pop_back(), path2.pop_back();
        

        cout << path1.size() + path2.size() << endl;
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