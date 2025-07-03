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

void solve(){
    /*
    case 1: 1 black papers fully cover the white paper -> "NO"
    
    case 2: Assuming a single black paper doesn't fully cover the white paper 
            if there is a gap between 2 black papers -> "YES"
            same for y
    
    case 3: Assuming there is not "gap" between 2 black papers
            minLowX = min(x3,x5)
            maxHighX = max(x4,x6)
            if maxHighX < x2 or minLowX > x1 -> "YES"
            same for y
  
    case 4: assuming above cases passed, 
            find the non-overlap area in (minLowX, minLowY), (maxHighX,maxHighU) and check the four point of the white paper, if any point is the non-overlap area
                then YES
                else no 
    */

    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    int x3,y3,x4,y4; cin >> x3 >> y3 >> x4 >> y4;
    int x5,y5,x6,y6; cin >> x5 >> y5 >> x6 >> y6;
    
    //case 1
    if (x3 <= x1 && y3 <= y1  && x4 >= x2 && y4 >= y2){
        cout << "NO" << endl;
        return;
    }

    if (x5 <= x1 && y5 <= y1  && x6 >= x2 && y6 >= y2){
        cout << "NO" << endl;
        return;
    }

    //case 2
    int maxLowX = max(x3,x5);
    int minHighX = min(x4,x6);
    if (maxLowX - minHighX > 0){
        cout << "YES" << endl;
        return;
    }

    int maxLowY = max(y3,y5);
    int minHighY = min(y4,y6);
    if (maxLowY - minHighY > 0){
        cout << "YES" << endl;
        return;
    }

    //case 3
    int minLowX = min(x3,x5);
    int maxHighX = max(x4,x6);
    if (maxHighX < x2 or minLowX > x1){
        cout << "YES" << endl;
        return;
    }
    int minLowY = min(y3,y5);
    int maxHighY = max(y4,y6);
    if (maxHighY < y2 or minLowY > y1){
        cout << "YES" << endl;
        return;
    }

    //case 4    
    vector<pair<Point,Point>> non_overlap{
        {//bottom-left
            Point(minLowX, minLowY),
            Point(maxLowX, maxLowY)
        },
        {//top-left
            Point(minLowX, maxHighY),
            Point(maxLowX, minHighY)
        },
        {//top-right
            Point(maxHighX, maxHighY),
            Point(minHighX, minHighY)
        },
        {//bottom-right
            Point(maxHighX, minLowY),
            Point(minHighX, maxLowY)
        },
    };

    if (x1 < non_overlap[0].second.x && y1 < non_overlap[0].second.y)
        cout << "YES" << endl;
    else if (x1 < non_overlap[1].second.x && y2 > non_overlap[1].second.y)
        cout << "YES" << endl;
    else if (x2 > non_overlap[2].second.x && y2 > non_overlap[2].second.y)
        cout << "YES" << endl;
    else if (x2 > non_overlap[3].second.x && y1 < non_overlap[3].second.y)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;



    for (auto points : non_overlap){

    }

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}