#include<bits/stdc++.h>

#define int long long 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define oo 1e10

const int mod = 1e9+7;
using namespace std;

random_device dev;
mt19937 rng(dev());
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

static bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.first < b.first;
}

static bool cmp2(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
}

vector<int> reduce(vector<int> &diff, int s){
    vector<pair<int,int>> diffIndexed;
    FOR(i,0,diff.size())
        diffIndexed.push_back({diff[i],i});
    sort(all(diffIndexed), cmp);

    vector<pair<int,int>> sortedDiffIndexed(diffIndexed.begin(), diffIndexed.begin() + s);
    sort(all(sortedDiffIndexed), cmp2);

    vector<int> res;
    res.push_back(sortedDiffIndexed[0].first);
    FOR(i,1,sortedDiffIndexed.size()){
        if (sortedDiffIndexed[i].second - sortedDiffIndexed[i - 1].second > 1)
            res.push_back(1e10);
        res.push_back(sortedDiffIndexed[i].first);
    }

    return  res;
}

void solve(){
    int K,N; cin >> K >> N;
    vector<int> t(N);
    FOR(i,0,N)
        cin >> t[i];
    sort(all(t));
    vector<int> diff;
    FOR(i,1,N)
        diff.push_back(t[i] - t[i - 1]);

    if (diff.size() > 3 * K)
        diff = reduce(diff, 3*K);

    int s = diff.size();
    vector<vector<vector<int>>> dp(3,vector<vector<int>>(K + 1, vector<int>(2,oo))); //if dp[j][k][t] == oo means invalid
    FOR(j,0,3)
        dp[j][0][0] = 0;
    // dp[0][1][0] = oo;

    dp[0][1][1] = diff[0];
    int res = min(dp[0][K][0], dp[0][K][1]);
    
    if (s > 1){
        dp[1][1][0] = min(dp[0][1][1],dp[0][1][0]);
        dp[1][1][1] = diff[1];
        res = min(dp[1][K][0], dp[1][K][1]);
    }

    FOR(j,2,s){
        FOR(k,1,min(K + 1,j/2 + 2) ){
            dp[j % 3][k][0] = min(dp[(j - 1) % 3][k][1],dp[(j - 1) % 3][k][0]);
            dp[j % 3][k][1] = min(dp[(j - 2) % 3][k-1][1] + diff[j],dp[(j - 2) % 3][k-1][0] + diff[j]);
        }
        res = min({res, dp[j % 3][K][0], dp[j % 3][K][1]});
        int a = 0;
    }

    cout << res << endl;

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}