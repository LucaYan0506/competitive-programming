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
    int x,y,z;
    bool picked;
    int originIndex;
    Point(){
        x = -1;
        y = -1;
        z = -1;
        picked = false;
        originIndex = -1;
    }
    Point(int first, int second, int third, int fourth){
        x = first;
        y = second;
        z =  third;
        originIndex = fourth;
        picked = false;
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

static bool cmp1(Point *p1, Point *p2){
    return p1->z < p2->z;
}

static bool cmp2(Point *p1, Point *p2){
    return p1->y < p2->y;
}

static bool cmp3(Point *p1, Point *p2){
    return p1->x < p2->x;
}


void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n){
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].originIndex = i + 1;
    }

    map<int,vector<Point*>> groupByX;
    FOR(i,0,n)
        groupByX[p[i].x].push_back(&p[i]);
  

    //for each group with same x, group by y
    map<pair<int,int>,vector<Point*>> groupByY;
    for (auto &[x,points] : groupByX){
        for (auto point : points)
            groupByY[{x,point->y}].push_back(point);
    }

    for (auto [y,points] : groupByY){
        sort(all(points),cmp1); //sort by z
        for(int i = 0; i + 1< points.size(); i += 2){
            points[i]->picked = true;
            points[i + 1]->picked = true;
            cout << points[i]->originIndex << " " << points[i + 1]->originIndex << endl;
        }
    }

    for (auto [x,points] : groupByX){
        vector<Point*> newPoints;
        for (auto point : points)
            if (!point->picked)
                newPoints.push_back(point);
        
        points = newPoints;
        if (points.size() == 0)
            continue;
        sort(all(points),cmp2); //sort by y
        for(int i = 0; i + 1 < points.size(); i += 2){
            points[i]->picked = true;
            points[i + 1]->picked = true;
            cout << points[i]->originIndex << " " << points[i + 1]->originIndex << endl;
        }
    }

    vector<Point*> newPoints;
    for (auto &point : p)
        if (!point.picked)
            newPoints.push_back(&point);
    sort(all(newPoints),cmp3); // sort by x
    for(int i = 0; i + 1 < newPoints.size(); i += 2)
        cout << newPoints[i]->originIndex << " " << newPoints[i + 1]->originIndex << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}