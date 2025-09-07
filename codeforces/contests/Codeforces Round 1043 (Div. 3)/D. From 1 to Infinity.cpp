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

/*
def test(start, end):
    res = 0
    for i in range(start, end):
        s = str(i)
        for c in s:
            res += int(c)
    return res
*/

vector<int> cPow10(16);
vector<int> preComp(16);  //number of digits used from 0 to indexToNum[i] 
vector<int> preComp2(16); //sum of digits used from 0 to indexToNum[i]
vector<int> indexToNum(16);

int sumDigit(int n){
    int i = 0;
    while(indexToNum[i + 1] <= n)
        i++;

    if (i == 0)
        return n * (n + 1) / 2; 
    if (indexToNum[i + 1] == n)
        return preComp2[i]; 

    int res = preComp2[i];
    res += sumDigit(n - indexToNum[i] - 1);
    int remaining = n - indexToNum[i];
    i++;

    int j = 1;
    for(; j < 9 && remaining >= cPow10[i]; j++){
        res += cPow10[i] * j;
        remaining -= cPow10[i];
    }

    res += remaining * j;

    return res;
}

void solve(){
    int k; cin >> k;
    int n; // what number is at the kth digit
    int i = 0;
    while(i < preComp.size() && preComp[i + 1] <= k)
        i++;

    k -= preComp[i];
    n = indexToNum[i];
    i++;

    n += (k / i);
    k = k % i;

    int res = sumDigit(n);

    if (k > 0){
        string s = to_string(n + 1);
        s = s.substr(0,k);
        for (char c : s)
            res += (c - '0');
    }

    cout << res << endl;

}

int32_t main(){
    fastIO();
    int t = 1;
    cin >> t;

    cPow10[0] = 1;
    FOR(i,1,16){
        cPow10[i] = cPow10[i - 1] * 10;
        indexToNum[i] = indexToNum[i - 1] * 10 + 9;
        preComp[i] = preComp[i- 1] + i * 9 * cPow10[i - 1];
        preComp2[i] = preComp2[i - 1] * 10 + 45 * cPow10[i - 1];
    }


    while(t--)
        solve();

    return 0;
}