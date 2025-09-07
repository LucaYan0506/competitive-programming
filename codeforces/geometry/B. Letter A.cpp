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
    double x,y;
    Point(){
        x = -1;
        y = -1;
    }
    Point(double first, double second){
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

struct Vec{
    Point a,b;
    Vec(){
        a = Point();
        b = Point();
    }
    Vec(Point _a, Point _b){
        a = _a;
        b = _b;
    }

    bool has(Point p){
        return collinear(a,b,p) && min(a.y,b.y) <= p.y && p.y <= max(a.y,b.y);
    }

    bool collinear(Point a, Point b, Point c) {
        return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x) == 0;  
    }

};

double dotProduct(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}

double calcDist(Point a, Point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y);
}

//assume first.a == second.a
//assume third.a connect with first, and third.b connect with second
bool check1(Vec first, Vec second, Vec third){
    auto dotRes = dotProduct(first.b - first.a, second.b - first.a);
    double totLen = calcDist(first.b, first.a) * calcDist(second.b, first.a);
    if (0 >= dotRes || dotRes * dotRes > totLen)
        return false; //second condition not met

    int d1 = calcDist(first.a, third.a);
    int d2 = calcDist(first.b, third.a);

    if (16*min(d1,d2) < max(d1,d2))
        return false; //third cond not met

    d1 = calcDist(second.a, third.b);
    d2 = calcDist(second.b, third.b);
    if (16*min(d1,d2) < max(d1,d2))
        return false; //third condition nto met

    return true;
}

bool check(vector<Vec> &vec){
    int sum = 3;
    auto helper = [&](int i, int j){
        int k = sum - i - j;

        vec[k] = Vec(vec[k].b, vec[k].a); // swap
        if (vec[i].has(vec[k].a) && vec[j].has(vec[k].b))
            if (check1(vec[i], vec[j], vec[k]))
                return true;
        vec[k] = Vec(vec[k].b, vec[k].a); // swap it back
        if (vec[i].has(vec[k].a) && vec[j].has(vec[k].b))
            if (check1(vec[i], vec[j], vec[k]))
                return true;

        return false;
    };
    
    FOR(i,0,3)
        FOR(j, i + 1, 3)
            if (vec[i].a == vec[j].a){
                if (helper(i,j))
                    return true;
            }else if (vec[i].b == vec[j].b){
                vec[i] = Vec(vec[i].b, vec[i].a); // swap 
                vec[j] = Vec(vec[j].b, vec[j].a); // swap 

                if (helper(i,j))
                    return true;

                vec[i] = Vec(vec[i].b, vec[i].a); // swap it back
                vec[j] = Vec(vec[j].b, vec[j].a); // swap it back         
            }else if (vec[i].a == vec[j].b){
                vec[j] = Vec(vec[j].b, vec[j].a); // swap 

                if (helper(i,j))
                    return true;

                vec[j] = Vec(vec[j].b, vec[j].a); // swap it back   
            }else if (vec[i].b == vec[j].a){
                vec[i] = Vec(vec[i].b, vec[i].a); // swap 

                if (helper(i,j))
                    return true;

                vec[i] = Vec(vec[i].b, vec[i].a); // swap it back
            }
    
    return false;
}

void solve(){
    vector<Vec> vec(3);
    FOR(i,0,3)  
        cin >> vec[i].a.x >> vec[i].a.y >> vec[i].b.x >> vec[i].b.y;

    if (check(vec))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}