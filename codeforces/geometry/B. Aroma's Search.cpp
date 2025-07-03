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
    int x,y;
    Point(){
        x = -1;
        y = -1;
    }
    Point(int first, int second){
        x = first;
        y = second;
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

int MAXVAL = 2e16;

int calcDist(Point p1, Point p2){
    int res = 0;
    if (p1.x > p2.x)
        res += p1.x - p2.x;
    else
        res += p2.x - p1.x;

    if (p1.y > p2.y)
        res += p1.y - p2.y;
    else
        res += p2.y - p1.y;

    return res;
}

void solve(){
    int x0,y0,ax,ay,bx,by; cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    int xs,ys,t; cin >> xs >> ys >> t;
    vector<Point> dataNodes;
    Point curr = Point(x0,y0);
    dataNodes.push_back(curr);
    while(curr.x < MAXVAL && curr.y < MAXVAL){
        curr = Point(curr.x*ax+bx, curr.y*ay+by);
        dataNodes.push_back(curr);
    }


    int maxi = 0;
    FOR(end,0,dataNodes.size())
    FOR(i,0,end + 1){
        Point currPos = Point(xs,ys);
        int currT = t;
        int cnt = 0;

        //left
        FORI(j,end - 1, i - 1){
            int temp = calcDist(currPos, dataNodes[j]);
            currT -= temp;
            currPos = dataNodes[j];
            if (currT >= 0)
                cnt++;
            else    
                break;
        }
        //right
        FOR(j,end, dataNodes.size()){
            currT -= calcDist(currPos, dataNodes[j]);
            currPos = dataNodes[j];
            if (currT >= 0)
                cnt++;
            else    
                break;
        }
        maxi = max(maxi, cnt);
    }

    cout << maxi << endl;
    
  
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}