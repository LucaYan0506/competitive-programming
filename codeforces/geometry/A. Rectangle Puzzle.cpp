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
const double eps = 1e-12;
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

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

struct Line{
    double a,b,c; // ax + by + c = 0 === -dy(x) + dx(y) + c = 0
    Line(Point p1, Point p2){
        double dy = p1.y - p2.y, dx = p1.x - p2.x;
        // //normalize
        // if (dy == 0)
        //     dx /= dx;
        // if (dx == 0)
        //     dy /= dy;

        // int g = gcd(dy,dx);
        // dy /= g; dx /= g;

        // if (dx < 0)
        //     dy = -dy, dx = -dx;
        a = -dy; b = dx; c =-a*p1.x - b*p1.y;
    }  

    double getY(double x){
        return -(a*x+c)/b;
    }
};

Point rotateP(Point p, double alpha){
    Point res = Point(p.x*cos(alpha) - p.y*sin(alpha), p.x*sin(alpha) + p.y*cos(alpha));
    return res;
}

Point intersectionP(Line l1, Line l2){
    double x = (-l1.c*l2.b + l2.c*l1.b) / (l2.b*l1.a - l1.b*l2.a);
    if (abs(l1.b) < eps)
        return Point(x,l2.getY(x));
    return Point(x,l1.getY(x));
}
const double PI = acos(-1);
void solve(){
    int w,h; cin >> w >> h;
    double alpha, alphaDeg; cin >> alphaDeg;
    if (alphaDeg == 0 || alphaDeg == 180){
        cout << w*h << endl;
        return;
    }
    if (alphaDeg > 90)
        alphaDeg = 180 - alphaDeg;
    alpha = alphaDeg * PI / 180;
    Point a = Point(-w/2., -h/2.);
    Point b = Point(w/2., -h/2.);
    Point c = Point(w/2.,h/2.);
    Point d = Point(-w/2., h/2.);
    Line baseA1 = Line(a,b);
    Line baseA2 = Line(c,d);//
    Line heightA1 = Line(b, c);
    
    Point a1 = rotateP(a, alpha), b1 = rotateP(b, alpha), c1 = rotateP(c, alpha), d1 = rotateP(d, alpha);

    Line baseB1 = Line(a1, b1);
    Line baseB2 = Line(c1, d1);
    Line heightB1 = Line(b1, c1);//

    double res;
    if (alphaDeg == 90 || intersectionP(baseB1, heightA1).y >= c.y || intersectionP(baseB1, heightA1).y <= b.y){ //case 1: rombus
        double x = min(w, h);
        res = x * x / sin(alpha);
    }else{
        res = w*h;

        double resB = b.x - intersectionP(baseB1, baseA1).x;
        double resH = intersectionP(baseB1, heightA1).y - b.y;
        res -= resB*resH;

        resB = c.x - intersectionP(heightB1, baseA2).x;
        resH = c.y - intersectionP(heightB1, heightA1).y;
        
        res -= resB*resH;
    }

    cout << setprecision(16);
    cout << res << endl;

}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}