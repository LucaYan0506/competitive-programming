#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int main(){
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    int n; cin >> n;
    int size = 1e9 + 1;
    // vector<vector<bool>> grid(size, vector<bool>(size, false));
    map<int,vector<pair<int,int>>> valid; 
    map<pair<int,int>,bool> visited;

    vector<pair<int,int>> dirs = {
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,-1},
        {0,1},
        {1,-1},
        {1,0},
        {1,1},
    };

    for (int i = 0; i < n; i++){
        int r,a,b;
        cin >> r >> a >> b;
        valid[r].push_back({a,b});
    }
    
    queue<pair<int,int>> q;
    q.push({x1,y1});
    int cost = -1;

    while(!q.empty()){
        int q_size = q.size();
        cost++;
        while(q_size--){
            auto curr = q.front();
            q.pop();

            if (curr.first == x2 && curr.second == y2){
                cout << cost;
                return 0;
            }
            
            for (auto dir : dirs){
                pair<int,int> newPos = {curr.first + dir.first, curr.second + dir.second};
                if (newPos.first < 0 || newPos.first >= size || newPos.second < 0 || newPos.second >= size || !valid.count(newPos.first) || visited.count(newPos))
                    continue;

                for (auto v : valid[newPos.first]){
                    if (newPos.second >= v.first && newPos.second <= v.second){
                        q.push({newPos.first, newPos.second});
                        visited[newPos] = true;
                        break;
                    }
                }
            }
        }
    

    }

    cout << "-1";
    return 0;
}