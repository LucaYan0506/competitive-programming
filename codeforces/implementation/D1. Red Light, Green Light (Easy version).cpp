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

static bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.first < b.first;
}

bool isRed(pair<int,int> pd, int t, int k){
    return (t - pd.second) % k == 0;
}


void solve(){
    int n,k; cin >> n >> k;
    vector<pair<int,int>> pd(n);
    FOR(i,0,n)
        cin >> pd[i].first;
    FOR(i,0,n)
        cin >> pd[i].second;
    sort(all(pd),cmp);
    vector<int> p(n);
    FOR(i,0,n)
        p[i] = pd[i].first;
    int q; cin >> q;
    FOR(i,0,q){
        int curr; cin >> curr;
        vector<vector<bool>> visited(n,vector<bool>(2,false));
        bool posDir = true;
        int t = 0;
        if (binary_search(all(p), curr) && isRed(pd[lower_bound(all(p),curr) - p.begin()], t, k))
            posDir = false;

        while(true){
            auto temp = upper_bound(all(p),curr);
            int closestPIndex = temp - p.begin();
            if (temp == p.end() && posDir){
                cout << "YES" << endl;
                break;
            }
            if (!posDir){
                temp = lower_bound(all(p),curr);
                if (temp == p.begin()){
                    cout << "YES" << endl;
                    break;
                }
                closestPIndex = temp - p.begin() - 1;
            }

            int diff = abs(curr - pd[closestPIndex].first);
            t += diff;
            if (posDir)
                curr += diff;
            else 
                curr -= diff;
            
            if (curr <= 0){
                cout << "YES" << endl;
                break;
            }


            if (isRed(pd[closestPIndex], t, k)){
                if (visited[closestPIndex][posDir]){
                    cout << "NO" << endl;
                    break;
                }

                visited[closestPIndex][posDir] = true;
                posDir = !posDir;
            }
        }
    }

    
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}