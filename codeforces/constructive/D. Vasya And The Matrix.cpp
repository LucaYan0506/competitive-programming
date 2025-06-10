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
    int i,j;
    Point(){
        i = -1;
        j = -1;
    }
    Point(int first, int second){
        i = first;
        j = second;
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
        return abs(a.i - b.i) + abs(a.j - b.j);
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

int xorVec(vector<int> l, int digit = -1){
    int res = 0;
    if (digit == -1)
        for (int x : l)
            res = res ^ x;
    else
        for (int x : l)
            res = res ^ (x & digit);
    
    return res;
}

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n), b(m);
    FOR(i,0,n)
        cin >> a[i];
    FOR(i,0,m)
        cin >> b[i];

    if (xorVec(a) != xorVec(b)){
        cout << "NO" << endl;
        return;
    }

    vector<vector<int>> matrix(n,vector<int>(m));
    FOR(j,0,m)
        matrix[0][j] = b[j];

    FOR(i,0,n){
        int j = 0;
        FOR(k,0,32){
            int digit = 1 << k;
            int xorRes = xorVec(matrix[i], digit);
            int curr = a[i] & digit;
            if (curr != xorRes){
                int newI = i + 1;

                if ((matrix[i][j] & digit) == 0){
                    matrix[i][j] += digit;
                    if ((matrix[newI][j] & digit) == 0)
                        matrix[newI][j] += digit;
                    else
                        matrix[newI][j] -= digit;
                }
                else{
                    matrix[i][j] -= digit;
                    if ((matrix[newI][j] & digit) == 0)
                        matrix[newI][j] += digit;
                    else
                        matrix[newI][j] -= digit;
                }
            }
        }
    }

    cout << "YES" << endl;
    FOR(i,0,n){
        FOR(j,0,m)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}