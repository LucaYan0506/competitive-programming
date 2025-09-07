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
    int x,y,z;
    Point(){
        x = -1;
        y = -1;
        z = -1;
    }
    Point(int first, int second, int third){
        x = first;
        y = second;
        z = third;
    }

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
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

int calcDistSq(Point p1, Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)*(p1.z-p2.z);
}

bool check(vector<Point> p){
    int l = oo;
    FOR(i,0,8)
        FOR(j,0,8)
            if (i != j)
                l = min(l, calcDistSq(p[i], p[j]));

    FOR(i,0,8){
        int cnt1 = 0; //1L 
        int cnt2 = 0; //2L
        int cnt3 = 0; //3l
        FOR(j,0,8)
            if (calcDistSq(p[i],p[j]) == l)
                cnt1++;
            else if (calcDistSq(p[i],p[j]) == 2*l)
                cnt2++;
            else if (calcDistSq(p[i],p[j]) == 3*l)
                cnt3++;

        if (cnt1 != 3 || cnt2 != 3 || cnt3 != 1)
            return false;
    }

    return true;
}

vector<Point> shuffle(Point p1){
    vector<Point> res;
    res.push_back(Point(p1.x,p1.y,p1.z));
    res.push_back(Point(p1.x,p1.z,p1.y));
    res.push_back(Point(p1.y,p1.x,p1.z));
    res.push_back(Point(p1.y,p1.z,p1.x));
    res.push_back(Point(p1.z,p1.y,p1.x));
    res.push_back(Point(p1.z,p1.x,p1.y));

    return res;
}

void solve(){
    vector<Point> p(8);
    FOR(i,0,8)
        cin >> p[i].x >> p[i].y >> p[i].z;

    vector<vector<Point>> possibleComb(8);
    FOR(i,1,8)
        possibleComb[i] = shuffle(p[i]);
    
    // FOR(a1,0,6)
    FOR(a2,0,6)
    FOR(a3,0,6)
    FOR(a4,0,6)
    FOR(a5,0,6)
    FOR(a6,0,6)
    FOR(a7,0,6)
    FOR(a8,0,6){
        vector<Point> newSeq;
        // newSeq.push_back(possibleComb[0][a1]);
        newSeq.push_back(p[0]);
        newSeq.push_back(possibleComb[1][a2]);
        newSeq.push_back(possibleComb[2][a3]);
        newSeq.push_back(possibleComb[3][a4]);
        newSeq.push_back(possibleComb[4][a5]);
        newSeq.push_back(possibleComb[5][a6]);
        newSeq.push_back(possibleComb[6][a7]);
        newSeq.push_back(possibleComb[7][a8]);
        
        //make sure that they are distinct points
        set<Point> s;
        for (Point x : newSeq)
            s.insert(x);

        if (s.size() == 8 && check(newSeq)){
            cout << "YES" << endl;
            FOR(i,0,8)
                cout << newSeq[i].x << " " << newSeq[i].y << " " << newSeq[i].z << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int32_t main(){
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
