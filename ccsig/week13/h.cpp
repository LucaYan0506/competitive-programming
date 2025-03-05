#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()

const int mod = 1e9+7;
using namespace std;

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

static bool cmp(vector<int> &a, vector<int> & b){
    if (a[0] == b[0])
        return a[1] > b[1];
    
    return a[0] < b[0];
}

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> edges(m,vector<int>(3));//edges[i][0] weight  edges[i][1] = {1 or 0} edges[i][2] = origin index
    vector<string> res(m);
    vector<bool> isConnected(n,false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> previous;
    FOR(i, 0,m){
        cin >> edges[i][0] >> edges[i][1];
        edges[i][2] = i;
    }
    //sort based on weight
    sort(all(edges),cmp);

    int currNotUsedV = 1;
    int extraStart = 1;
    int extraEnd = 1;
    for (auto edge : edges){
        if (edge[1] == 1){
            res[edge[2]] = "1 " + to_string(currNotUsedV + 1);
            currNotUsedV++;
            continue;
        }

        while(isConnected[extraEnd] || extraEnd == extraStart){
            extraEnd++;
            if (extraEnd >= currNotUsedV){
                extraStart++;
                extraEnd = 1;
                isConnected = vector<bool>(n);
                while(!previous.empty() && previous.top().first < extraStart)
                    previous.pop();
                while(!previous.empty() && previous.top().first == extraStart){
                    isConnected[previous.top().second] = true;
                    previous.pop();
                }
                
            } 
            if (extraStart >= currNotUsedV){
                cout << "-1";
                return;
            }
        }
        isConnected[extraEnd] = true;
        previous.push({extraEnd,extraStart});
        res[edge[2]] = to_string(extraStart + 1)   + " " + to_string(extraEnd + 1);
    }

    for (auto x : res)
        cout << x << endl;;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}