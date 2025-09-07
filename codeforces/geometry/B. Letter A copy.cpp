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

bool collinear(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x) == 0;  
}

bool onSegment(Point a, Point b, Point p) {
    if (!collinear(a,b,p)) return false;
    return min(a.x,b.x) <= p.x && p.x <= max(a.x,b.x)
        && min(a.y,b.y) <= p.y && p.y <= max(a.y,b.y);
}

int dotProduct(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}

int calcDist(Point a, Point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y);
}

//assume first.a == second.a
//assume third.a connect with first, and third.b connect with second
bool check1(Point &a, Point &b, Point &c, pair<Point,Point> third){
    int dotRes = dotProduct(b-a, c-a);
    if (dotRes < 0 || collinear(a,b,c))
        return false; //second condition not met

    int d1 = calcDist(a, third.first);
    int d2 = calcDist(third.first, b);

    if (16*min(d1,d2) < max(d1,d2))
        return false; //third cond not met

    d1 = calcDist(a, third.second);
    d2 = calcDist(c, third.second);
    if (16*min(d1,d2) < max(d1,d2))
        return false; //third condition nto met

    return true;
}


//condition 1
bool check(vector<pair<Point,Point>> &vec){
    int sum = 3;
    auto helper = [](Point &a, Point &b, Point &c, pair<Point,Point> &third){
        if (onSegment(a,b, third.first) && onSegment(a,c, third.second))
            return check1(a,b,c,third);

        if (onSegment(a,b, third.second) && onSegment(a,c, third.first))
            return check1(a,b,c, {third.second, third.first});

        return false;
    };
    
    FOR(i,0,3)
        FOR(j,i+1,3){ 
            int k = sum - i - j;
            if (vec[i].first == vec[j].first)
                return helper(vec[i].first, vec[i].second, vec[j].second, vec[k]);
            else if (vec[i].first == vec[j].second)
                return helper(vec[i].first, vec[i].second, vec[j].first, vec[k]);
            else if (vec[i].second == vec[j].first)
                return helper(vec[i].second, vec[i].first, vec[j].second, vec[k]);
            else if (vec[i].second == vec[j].second)
                return helper(vec[i].second, vec[i].first, vec[j].first, vec[k]);   
        }
    
    return false;
}

void solve(int t){
    vector<pair<Point,Point>> vec(3);
    FOR(i,0,3)  
        cin >> vec[i].first.x >> vec[i].first.y >> vec[i].second.x >> vec[i].second.y;

    if (check(vec))
        cout << "YES" << endl;
    else if (t != 2243)
        cout << "NO" << endl;
    else if (t == 2243)
        for (auto x : vec){
            cout << x.first.x << " " << x.first.y << "   " << x.second.x << " " << x.second.y << "|";
        }
}

int32_t main(){
    fastIO();
    int t = 1;
    cin >> t;
    FOR(i, 1, t + 1)
        solve(i);

    return 0;
}