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

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> dp1(n + 2,vector<int>(m + 2,-oo)); //max dist from 1,1 to i,j
    vector<vector<int>> dp2(n + 2,vector<int>(m + 2,-oo)); //max dist from 1,m+1 to i,j
    vector<vector<int>> dp3(n + 2,vector<int>(m + 2,-oo)); //max dist from n+1,1 to i,j
    vector<vector<int>> dp4(n + 2,vector<int>(m + 2,-oo)); //max dist from n1,m+1 to i,j

    vector<vector<bool>> isBlack(n + 1,vector<bool>(m + 1)); //isBlack[i][j] = 1 means black cell
    FOR(i,1,n + 1){
        string temp; cin >> temp;
        FOR(j,1,m + 1)
            if (temp[j - 1] == 'B')
                isBlack[i][j] = 1;
    }

    FOR(i,1,n + 1)
        FOR(j,1,m + 1){
            if (isBlack[i][j])
                dp1[i][j] = max({0ll, dp1[i - 1][j - 1] + 2, dp1[i - 1][j] + 1, dp1[i][j - 1] + 1});
            else
                dp1[i][j] = max({dp1[i - 1][j - 1] + 2, dp1[i - 1][j] + 1, dp1[i][j - 1] + 1});
        }

    FOR(i,1,n + 1)
        FORI(j,m, 0){
            if (isBlack[i][j])
                dp2[i][j] = max({0ll, dp2[i - 1][j + 1] + 2, dp2[i - 1][j] + 1, dp2[i][j + 1] + 1});
            else
                dp2[i][j] = max({dp2[i - 1][j + 1] + 2, dp2[i - 1][j] + 1, dp2[i][j + 1] + 1});
        }

    FORI(i,n, 0)
        FOR(j,1,m + 1){
            if (isBlack[i][j])
                dp3[i][j] = max({0ll, dp3[i + 1][j - 1] + 2, dp3[i + 1][j] + 1, dp3[i][j - 1] + 1});
            else
                dp3[i][j] = max({dp3[i + 1][j - 1] + 2, dp3[i + 1][j] + 1, dp3[i][j - 1] + 1});
        }

    FORI(i,n, 0)
        FORI(j,m, 0){
            if (isBlack[i][j])
                dp4[i][j] = max({0ll, dp4[i + 1][j + 1] + 2, dp4[i + 1][j] + 1, dp4[i][j + 1] + 1});
            else
                dp4[i][j] = max({dp4[i + 1][j + 1] + 2, dp4[i + 1][j] + 1, dp4[i][j + 1] + 1});
        }

    int minDist = oo;
    Point res;
    FOR(i,1,n + 1)
        FOR(j,1,m + 1){
            int maxDist = max({dp1[i][j], dp2[i][j], dp3[i][j], dp4[i][j]});
            if (maxDist < minDist){
                minDist = maxDist;
                res = Point(i,j);
            }
        }

    cout << res.i << " " << res.j << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}