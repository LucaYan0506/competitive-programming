#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b, step) for (int i = (a); i < (b); i += (step))
#define endl "\n"

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

struct Disk{
    struct Centre{
        int x;
        int y;
    }centre;
    int radius;
    int mark; // -1 or 1 (o means unmarked)
    bool invalid; 
};

vector<Disk> disks;
vector<vector<int>> edges;

int dist(Disk a, Disk b){
    int x = a.centre.x - b.centre.x;
    int y = a.centre.y - b.centre.y;
    double res = sqrt(x*x + y*y);
    int res_int = sqrt(x*x + y*y);
    if (res_int == res)
        return res_int;

    return -1;
}

void setDiskInvalid(int i){
    if (disks[i].invalid)
        return;

    disks[i].invalid = true;
    for (auto x : edges[i])
        setDiskInvalid(x);
}

void markDisk(int i, int mark){
    if (disks[i].invalid)
        return;
        
    disks[i].mark = mark;

    int newMark;
    if (mark == 1)
        newMark = -1;
    else
        newMark = 1;

    for (auto x : edges[i]){
        if (disks[x].mark == 0)
            markDisk(x,newMark);

        if (disks[x].mark != newMark){
            setDiskInvalid(i);
            return;
        }
        
    }


    
}

pair<int,int> check(int i){
    pair<int,int> res = {0,0}; //res.first = count of -1 res.second = count of 1
    if (disks[i].mark == -1)
        res.first++;
    else 
        res.second++;

    disks[i].invalid = true;
    for (auto x : edges[i]){
        if (disks[x].invalid)
            continue;
        auto [count1,count2] = check(x);
        res.first += count1;
        res.second += count2;
    }

    return res;
}

void solve(){
    int n; cin >> n;
    disks = vector<Disk>(n);
    edges = vector<vector<int>>(n);
    FOR (i,0,n,1)
        cin >> disks[i].centre.x >> disks[i].centre.y >> disks[i].radius;

    FOR (i, 0, n, 1)
        FOR (j, i + 1, n, 1)
            if (dist(disks[i],disks[j]) == disks[i].radius + disks[j].radius)
                edges[i].push_back(j),edges[j].push_back(i);

    FOR (i, 0, n, 1)
        if (disks[i].mark == 0)
            markDisk(i,1);
    

    bool flag = false;
    FOR (i, 0, n, 1){
        if (disks[i].invalid)
            continue;
        auto [count1, count2] = check(i);
        if (count1 != count2){
            flag = true;
            break;
        }        
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}