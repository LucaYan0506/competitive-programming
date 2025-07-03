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

static bool cmp1(Point p1, Point p2){
    if (p1.x == p2.x){
        if (p1.y == p2.y)
            return p1.z < p2.z;

        return p1.y < p2.y;

    }
    return p1.x < p2.x;
}

static bool cmp2(Point p1, Point p2){
    if (p1.y == p2.y){
        if (p1.x == p2.x)
            return p1.z < p2.z;

        return p1.x < p2.x;
    }
    
    return p1.y < p2.y;
}

static bool cmp3(Point p1, Point p2){
    if (p1.z == p2.z){
        if (p1.x == p2.x)
            return p1.y < p2.y;

        return p1.x < p2.x;
    }


    return p1.z < p2.z;
}

//calc distance squared
int calcDist(Point p1, Point p2){
    return pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2) + pow((p1.z - p2.z),2);
}

void solve(){
    int n; cin >> n;
    vector<Point> p(n);
    FOR(i,0,n){
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].originIndex = i + 1;
    }

    FOR(i,0,n){
        if (p[i].picked)
            continue;
        
        int mini = oo;
        int index = -1;

        FOR(j, i + 1, n){
            if (p[j].picked)
                continue;
            int dist = calcDist(p[i],p[j]);
            if (dist < mini){
                mini = dist;
                index = j;
            }
        }

        cout << p[i].originIndex << " " << p[index].originIndex << endl;
        p[i].picked = true;
        p[index].picked = true;
    }
  
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}