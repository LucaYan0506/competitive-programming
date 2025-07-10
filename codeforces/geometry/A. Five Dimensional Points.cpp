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
    int a,b,c,d,e;
    Point(){
        a = -1;
        b = -1;
        c = -1;
        d = -1;
        e = -1;
    }
    Point(int _a, int _b, int _c, int _d, int _e){
        a = _a;
        b = _b;
        c = _c;
        d = _d;
        e = _e;
    }

    Point operator-(const Point& other) const {
        Point res = Point(
            a - other.a,
            b - other.b,
            c - other.c,
            d - other.d,
            e - other.e
        );
        return res;
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

int dotProduct(Point p1, Point p2){
    return p1.a * p2.a + p1.b * p2.b + p1.c * p2.c + p1.d * p2.d + p1.e * p2.e;
}

//////////////////////////////////////////////////////
/////////////////triangle approach////////////////////
//////////////////////////////////////////////////////
/*
void solve(){
    int n; cin >> n;
    vector<pair<Point,int>> p(n);
    queue<pair<Point,int>> q;
    FOR(i,0,n){
        cin >> p[i].first.a >> p[i].first.b >> p[i].first.c >> p[i].first.d >> p[i].first.e;
        p[i].second = i;
        q.push(p[i]);
    }   

    while(q.size() >= 3){
        //note that every triangle has at least 2 acute angle, so only one of p1,p2,p3 can be potentially good
        auto [p1, i1] = q.front();q.pop();
        auto [p2, i2] = q.front();q.pop();
        auto [p3, i3] = q.front();q.pop();

        if (dotProduct(p1 - p2,p3 - p2) <= 0)
            q.push({p2,i2});
        else if (dotProduct(p2 - p1,p3 - p1) <= 0)
            q.push({p1,i1});
        else if (dotProduct(p2 - p3,p1 - p3) <= 0)
            q.push({p3,i3});
    }

    //at most 2 potential good point left, check if any of them is good
    vector<int> res;
    while(!q.empty()){
        auto [curr, k] = q.front();q.pop();
        bool flag = true;
        FOR(i,0,n){
            if (i == k)
                continue;
            FOR(j,i+1,n){
                if (j == k)
                    continue;

                if (dotProduct(p[i].first - curr,p[j].first - curr) > 0){
                    flag = false;
                    break;
                }
            }

            if (!flag)
                break;
        }

        if (flag)
            res.push_back(k);
    }

    sort(all(res)); //actually res.size() is at most 1, so no sort needed
    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i] + 1 << endl;
}
*/

//////////////////////////////////////////////////////
/////////////////naive for n <= 11/////////////////////
//////////////////////////////////////////////////////
/*
    note that for 2d dimension, we have at most 5 points (one at the origin and others at the axis (NOTE only one at negative y 
                                                                                                          and one at positive y, similar for other axis)) 
    at 5d dimension, we have 5 axis, so at most 11 points (one at the origin and 10 at axis)
*/
void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n)
        cin >> p[i].a >> p[i].b >> p[i].c >> p[i].d >> p[i].e;

    if (n > 11){
        cout << 0 << endl;
        return;
    }
    vector<int> res;
    FOR(i,0,n){
        bool flag = true;
        FOR(j,0,n){
            if (j == i)
                continue;
            FOR(k,0,n){
                if (k == i || j == k)
                    continue;
                if (dotProduct(p[j] - p[i],p[k] - p[i]) > 0){
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }

        if (flag)
            res.push_back(i);
    }

    // sort(all(res)); //actually res.size() is at most 1, so no sort needed
    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i] + 1 << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}