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
    int n,k; cin >> n >> k;
    int remainingLine = n - k;
    vector<int> endPoint(2*n + 1, -1);
    FOR(i,0,k){
        int x,y;cin >> x >> y;
        endPoint[x] = y;
        endPoint[y] = x;
    }

    int res = 0;

    //count intersection between fixed lines (it's always to get the max)
    vector<bool> counted(2*n + 1, false);
    FOR(i,1, 2 * n + 1){
        if (counted[i] == false && endPoint[i] != -1){
            counted[i] = true;
            counted[endPoint[i]] = true;
            vector<bool> localCounted(2*n + 1, false);
            int start = min(i,endPoint[i]);
            int end = max(i,endPoint[i]);
            FOR(curr, start, end){
                if (endPoint[curr] != -1 && localCounted[curr] == false){
                    localCounted[curr] = true;
                    localCounted[endPoint[curr]] = true;
                    if (endPoint[curr] > end || endPoint[curr] < start)
                        res++;
                }
            }
        }
    }

    res /= 2;
    
    //count intersection between non-fixed lines (it's always to get the max)
    res += (remainingLine * (remainingLine - 1)) / 2;

    FOR(i,1, remainingLine + 1){
        counted = vector<bool>(2*n + 1, false);
        int start = 0;
        FOR(j,0,i){
            start++;
            while(endPoint[start] != -1)
                start++;
        }

        int end = start;
        FOR(j,0,remainingLine){
            end++;
            while(endPoint[end] != -1)
                end++;
        }

        //count intersection between Line(start,end) and fixed lines
        FOR(curr, start, end + 1){
            if (endPoint[curr] != -1 && counted[curr] == false){
                counted[curr] = true;
                counted[endPoint[curr]] = true;
                if (endPoint[curr] > end || endPoint[curr] < start)
                    res++;
            }
        }
    }

    cout << res << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}