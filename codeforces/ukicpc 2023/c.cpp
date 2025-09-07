#include<bits/stdc++.h>

// #define int long long 
// #define double long double 
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
vector<double> a;
const double PI = acosl(-1);
double degToRad(double deg){
    return (deg / 180.0) * PI;
}

double calcArea(int i, int j){
    double theta = a[i] - a[j];
    return sin(theta) * 0.5;
}

// easy version of this problem: D. An overnight dance in discotheque
void solve(){
    int n, p; cin >> n >> p; 
    a = vector<double>(2*n);
    FOR(i,0,n){
        cin >> a[i];
        a[i + n] = a[i] + 360;
        a[i] = degToRad(a[i]);
        a[i + n] = degToRad(a[i + n]);
    }
    double res = -oo;

    FOR(s,0,n){
        vector<vector<double>> dp(2 * n, vector<double>(p + 1, -oo));
        dp[s][0] = 0;
        FOR(i, s, s + n){
            FOR(j,0,p ){
                for (int l = i + 1; l <= s + n; l++) {
                    dp[l][j + 1] = max(dp[l][j + 1], dp[i][j] + sin(a[l] - a[i]) / 2);
                }
            }
        }
        for (int k = 0; k <= p; ++k) {
            res = max(dp[s + n][k],res);
        }
    }
    cout << setprecision(16);
    cout << res * 1000000 << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}