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

using namespace std;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

struct Mirror {
    int score;     
    bool isFloor;  
    int left, right;
};

int hl, hr, n;  
int res = 0;
vector<Mirror> mirrors;

// Try a path with exactly T reflections
void tryPath(int T) {
    vector<bool> used(mirrors.size(), false);

    // line from (0,h1) to (100000, totalY)
    int totalX = 100000;
    int totalY = (T - 1) * 100 + hl; // unfold the box, so for each bounce, y+=100
    if (T % 2)
        totalY += hr;       // odd reflections: direct hr
    else
        totalY += 100 - hr; // even reflections: mirrored hr

    double inverseSlope = (double)totalX / totalY;

    double xPos = 0;   
    int score = 0;
    bool floorHit = true; 

    FOR(i,1,T+1){
        if (i == 1) 
            xPos += inverseSlope * hl; // first bounce at height hl
        else
            xPos += inverseSlope * 100; // afterwards full height 100

        bool found = false;
        FOR(j,0,n)
            if (mirrors[j].isFloor == floorHit && mirrors[j].left <= xPos && xPos <= mirrors[j].right) {

                if (used[j]) return; 
                used[j] = true;

                score += mirrors[j].score;
                found = true;
                break;
            }

        if (!found) 
            return; // no mirror hit

        floorHit = !floorHit; // switch side for next bounce
    }

    res = max(res, score);
}

void solve(){
    cin >> hl >> hr >> n;
    mirrors.resize(n);

    for (int i = 0; i < n; i++) {
        char c;
        cin >> mirrors[i].score >> c >> mirrors[i].left >> mirrors[i].right;
        mirrors[i].isFloor = c == 'F';
    }

    FOR(i,1,n+1)
        tryPath(i);

    // flipped orientation (mirror everything vertically)
    
    // Flip hole heights
    hl = 100 - hl;
    hr = 100 - hr;
    
    for (auto &m : mirrors)
        m.isFloor = !m.isFloor;

    FOR(i,1,n+1)
        tryPath(i);

    cout << res << endl;
}

int32_t main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    
    return 0;
}
