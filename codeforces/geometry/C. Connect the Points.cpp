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
        x = -oo;
        y = -oo;
    }
    Point(int first, int second){
        x = first;
        y = second;
    }
};
bool operator!=(const Point& p1, const Point& p2){
    return (p1.x == p2.x && p1.y ==p2.y) == false;
}

struct Line{
    Point p1, p2;
    Line(){
        p1 = Point();
        p2 = Point();
    }
    Line(Point first, Point second){
        p1 = first;
        p2 = second;
    }
};

Point intersectiontPoint(Line l1, Line l2){
    //if both are vertical/horizontal, they don't intersect
    if (l1.p1.x == l1.p2.x && l2.p1.x == l2.p2.x)
        return Point();
    if (l1.p1.y == l1.p2.y && l2.p1.y == l2.p2.y)
        return Point();

    //always set l1 as vertical line, 
    //so if l1 is horizontal swap l1 with l2
    if (l1.p1.y == l1.p2.y)
        return intersectiontPoint(l2,l1);


    //if l1.p1.x is not between l2
    if ((l2.p1.x >= l1.p1.x && l2.p2.x <= l1.p1.x) == false && (l2.p1.x <= l1.p1.x && l2.p2.x >= l1.p1.x) == false)
        return Point();

    //if l2.p1.y is not between l1
    if ((l1.p1.y >= l2.p1.y && l1.p2.y <= l2.p1.y) == false && (l1.p1.y <= l2.p1.y && l1.p2.y >= l2.p1.y) == false)
        return Point();
        
    return Point(l1.p1.x,l2.p1.y);
}

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
    vector<Point> p(3);
    FOR(i,0,3)
        cin >> p[i].x >> p[i].y;

    vector<Line> lines;
    int minY = oo,maxY = -oo;
    int minX = oo,maxX = -oo;
    FOR(i,0,3){
        minY = min(minY,p[i].y);
        minX = min(minX,p[i].x);

        maxY = max(maxY,p[i].y);
        maxX = max(maxX,p[i].x);
    }

        //all points are collinear
    if ((p[0].x == p[1].x && p[1].x == p[2].x) || (p[0].y == p[1].y && p[1].y == p[2].y)){
        cout << 1 << endl;
        cout << minX << " " << minY << " " << maxX << " " << maxY << endl;
        return;
    }

        //2 points are collinear
    FOR(i,0,3)
        FOR(j,i + 1,3){
            // vertical
            if (p[i].x == p[j].x){
                int k = 3 - i - j;
                cout << 3 << endl;
                cout << p[k].x << " " << p[k].y << " " << p[i].x << " " << p[k].y << endl;

                minY = min(p[i].y, p[j].y);
                maxY = max(p[i].y, p[j].y);
                if (minY <= p[k].y && maxY >= p[k].y){
                    cout << p[i].x << " " << p[k].y << " " << p[j].x << " " << p[j].y << endl;
                    cout << p[i].x << " " << p[k].y << " " << p[i].x << " " << p[i].y << endl;
                }else{
                    if (abs(p[k].y - minY) > abs(p[k].y - maxY)){
                        cout << p[i].x << " " << p[k].y << " " << p[j].x << " " << maxY << endl;
                        cout << p[j].x << " " << maxY << " " << p[j].x << " " << minY << endl;
                    }else{
                        cout << p[i].x << " " << p[k].y << " " << p[j].x << " " << minY << endl;
                        cout << p[j].x << " " << minY << " " << p[j].x << " " << maxY << endl;
                    }
                }
                
                return;
            }
            
            // horizontal
            if (p[i].y == p[j].y){
                int k = 3 - i - j;
                cout << 3 << endl;
                cout << p[k].x << " " << p[k].y << " " << p[k].x << " " << p[i].y << endl;

                minX = min(p[i].x, p[j].x);
                maxX = max(p[i].x, p[j].x);
                if (minX <= p[k].x && maxX >= p[k].x){
                    cout << p[k].x << " " << p[i].y << " " << p[j].x << " " << p[j].y << endl;
                    cout << p[k].x << " " << p[i].y << " " << p[i].x << " " << p[i].y << endl;
                }else{
                    if (abs(p[k].x - minX) > abs(p[k].x - maxX)){
                        cout << p[k].x << " " << p[i].y << " " << maxX << " " << p[j].y << endl;
                        cout << maxX << " " << p[j].y << " " << minX << " " << p[j].y << endl;
                    }else{
                        cout << p[k].x << " " << p[i].y << " " << minX << " " << p[j].y << endl;
                        cout << minX << " " << p[j].y << " " << maxX << " " << p[j].y << endl;
                    }
                }

                return;
            }
        }

    FOR(i,0,3){
        lines.push_back(Line(Point(p[i].x, minY), Point(p[i].x, maxY)));
        lines.push_back(Line(Point(minX, p[i].y), Point(maxX, p[i].y)));
    }

    Point criticalP;
    FOR(i,0,lines.size())
        FOR(j,i + 1,lines.size()){
            Point p = intersectiontPoint(lines[i],lines[j]);
            if (p.x == -oo && p.y == -oo)
                continue;

            if (p != lines[i].p1 && p != lines[i].p2 && p != lines[j].p1 && p != lines[j].p2){
                criticalP = p;
                break;
            }
        }


    cout << 6 << endl;
    FOR(i,0,3){
        Line line1 = Line(p[i], Point(p[i].x,criticalP.y));
        Line line2 = Line(Point(p[i].x,criticalP.y),criticalP);
        cout << p[i].x << " " << p[i].y << " " << p[i].x << " " << criticalP.y << endl;
        cout << p[i].x << " " << criticalP.y << " " << criticalP.x << " " << criticalP.y << endl;
    }

}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}


