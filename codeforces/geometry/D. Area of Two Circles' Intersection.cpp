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

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}
const double PI = acosl(-1);
double calcDist(double x1, double y1, double x2, double y2){
    return sqrtl((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

double calcChord(int r, double theta){
    return 0.5 * r * r * (theta - sinl(theta));
}



void solve(){
    double x1,y1,r1; cin >> x1 >> y1 >> r1;
    double x2,y2,r2; cin >> x2 >> y2 >> r2;
    // first circle always bigger than 2nd  
    if (r2 > r1){
        swap(x1,x2);
        swap(y1,y2);
        swap(r1,r2);
    }
    double a =  calcDist(x1,y1,x2,y2);
    //translate & rotate circles center, so:
    x1 = 0, y1 = 0;
    x2 = a, y2 = 0;

    cout << setprecision(16);

    // if whole 2nd circle inside first circle  
    if (x2 + r2 <= r1){
        cout << r2*r2*PI << endl;
        return;
    }

    // if no intersection point
    if (r1 <= x2 - r2){
        cout << 0 << endl;
        return;
    }

    /*
    previously I used atan to calculate the angle, but this gives me precision error
    because of division + atan
    double x = (r1*r1 + a*a - r2*r2) / (2*a); 
    double ya = sqrtl(r1*r1 - x*x),yb = -ya;
 
    double theta1 = 2 * atan(ya/x);
    double theta2 = 2 * atan(yb/(a-x));
    */

    // to avoid precision use acos (with cos rule)
    double theta1 = acosl((r1*r1 + a*a - r2*r2) / (2*a*r1))*2;
    double theta2 = acosl((r2*r2 + a*a - r1*r1) / (2*a*r2))*2;

    cout << calcChord(r1, theta1) + calcChord(r2, theta2) << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}