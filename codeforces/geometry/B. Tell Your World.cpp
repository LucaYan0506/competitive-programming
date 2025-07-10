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

struct Slope{
    int den, num;
    Slope(){
        den=-1;
        num=-1;
    }
    Slope(int a,int b){
        num = a;
        den = b;
        normalize();
    }

    void normalize(){
        //keep den positive
        if (den < 0){
            den = -den;
            num = -num;
        }

        int g = gcd(den,num);
        if (g != 0){
            den /= g;
            num /= g;
        }

        //vertical/horizontal line
        if (num == 0)
            den = den / abs(den);
        if (den == 0)
            num = num / abs(num);
    }

    bool operator==(const Slope&other) const{
        return den == other.den && num == other.num;
    }
    bool operator!=(const Slope&other) const{
        return den != other.den || num != other.num;
    }
};

Slope calcSlope(Point p1, Point p2){
    return Slope(
        p1.y - p2.y,
        p1.x - p2.x
    );
}

bool helper(vector<Point> p, int k){
    int n = p.size();
    Slope m; //potentialSlope
    bool found = false;
    FOR(i,0,n){
        if (i == k)
            continue;
        FOR(j,i+1,n){
            if (j == k)
                continue;
            if (calcSlope(p[k],p[i]) == calcSlope(p[k],p[j])){
                m = calcSlope(p[k],p[i]);
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    vector<Point> newP;
    if (found){ // if a line intersect p[k] and other 2 points (so at least 3 points)
        FOR(i,0,n)
            if (i != k && calcSlope(p[k],p[i]) != m)
                newP.push_back(p[i]);
    }else{ // if a line intersect only p[k] and the other line intersect the remaining pointer
        FOR(i,0,n)  
            if (i != k)
                newP.push_back(p[i]);
        m = calcSlope(newP[k], newP[1]);
    }


    bool flag = newP.size() != 0;
    FOR(i,0,newP.size()){
        FOR(j,i+1,newP.size())
            if (calcSlope(newP[i],newP[j]) != m)
                flag = false;
        
        if (!flag) 
            break;
    }

    return flag;
}

/*
//sol by checking the first 3 points
void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n){
        cin >> p[i].y;
        p[i].x = i;
    }

    if (n == 4){//special case: if each line intersection 2 points
        bool res = false;
        if (calcSlope(p[0],p[1]) == calcSlope(p[2],p[3]) && calcSlope(p[0],p[1]) != calcSlope(p[0],p[2]) && calcSlope(p[0],p[1]) != calcSlope(p[0],p[3]))
            res = true;
        else if (calcSlope(p[0],p[2]) == calcSlope(p[1],p[3]) && calcSlope(p[0],p[2]) != calcSlope(p[0],p[1]) && calcSlope(p[0],p[2]) != calcSlope(p[0],p[3]))
            res = true;
        else if (calcSlope(p[0],p[3]) == calcSlope(p[1],p[2]) && calcSlope(p[0],p[3]) != calcSlope(p[0],p[1]) && calcSlope(p[0],p[3]) != calcSlope(p[0],p[2]))
            res = true;

        if (res){
            cout << "YES" << endl;
            return;
        }
    }

    bool res = helper(p,0) || helper(p,1) || helper(p,2); //if n > 4, at least one line has 3 points, if n == 3 one line has only one point

    if (res)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}   
*/

//sol using random generator
void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n){
        cin >> p[i].y;
        p[i].x = i;
    }

    FOR(k,0,1000){
        int a = get_random(0,n - 1), b = get_random(0,n - 1);
        while(b == a)
            b = get_random(0,n - 1);
        
        Slope m = calcSlope(p[a],p[b]);
        vector<Point> newP;
        FOR(i,0,n){
            if (i == a)
                continue;
            if (calcSlope(p[a],p[i]) != m)
                newP.push_back(p[i]);
        }

        if (newP.size() == 0){
            cout << "NO" << endl;
            return;
        }

        bool flag = true;
        FOR(i,0,newP.size()){
            FOR(j,i+1,newP.size())
                if (calcSlope(newP[i],newP[j]) != m)
                    flag = false;
            
            if (!flag) 
                break;
        }

        if (flag){
            cout <<"YES" << endl;
            return;
        }
        
    }

    cout <<"NO" << endl;

}
int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}