
#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

class Compare {
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        }
};

//this approach doesn't, it's too slow
void diijkstras(int a, int n, int newW, int w, vector<vector<vector<int>>> &dp, vector<vector<pair<int,int>>> &edges){
                    //node cost
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    pq.push({a,0});
    int nodeVisited = 0;
    vector<int> visited(n + 1);
    //dijkstra's algo with one variation, time complexity O(V ElogV)
    while(!pq.empty() && nodeVisited < n){
        int size = pq.size();
        while(size--){
            auto [b,cost] = pq.top();
            pq.pop();
            if (visited[b])
                continue;

            visited[b] = true;
            nodeVisited++;
            dp[a][b][newW] = min(dp[a][b][newW], cost);
            for (auto [endNode, weight] : edges[b])
                if (!visited[endNode])
                    pq.push({endNode, cost + (weight > w)});
        }
    }
}

void solve(){
    int n,m,q; cin >> n >> m >> q;
    vector<vector<pair<int,int>>> edges(n + 1);//edges[i].first = end node, edges[i].second = weight
    map<int,int> weights;
    FOR (i, 0, m){
        int v, u, w; cin >> v >> u >> w;
        edges[v].push_back({u,w});
        edges[u].push_back({v,w});
        weights[w]++;
    }   

    int index = 0;
    for (auto &[key,val] : weights)
        val = index++;

    vector<vector<vector<int>>> dp (n + 1, vector<vector<int>>(n + 1,vector<int>(weights.size(),INT_MAX)));
    FOR (a, 1, n + 1){
        for (auto [w,newW] : weights){
            //this approach doesn't, it's too slow
            // diijkstras(a,n,newW,w, dp, edges);

            //0-1 bfs
                             //node cost
            deque<pair<int,int>> q;
            vector<int> v;
            q.push_back({a,0});
            vector<int> visited(n + 1);
            //dijkstra's algo with one variation, time complexity O(V ElogV)
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    auto [b,cost] = q.front();
                    q.pop_front();
                    if (visited[b])
                        continue;

                    visited[b] = true;
                    dp[a][b][newW] = min(dp[a][b][newW], cost);
                    for (auto [endNode, weight] : edges[b])
                        if (!visited[endNode]){
                            if (weight > w)
                                q.push_back({endNode, cost + 1});
                            else
                                q.push_front({endNode, cost});
                        }
                }
            }
        }
    }

    FOR (i, 0, q){
        int a,b,k; cin >> a >> b >> k;
        for (auto [w,newW] : weights){
            if (dp[a][b][newW] < k){
                cout << w << " ";
                break;
            }
        }
    }
    cout << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}