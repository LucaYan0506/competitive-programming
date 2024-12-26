#include<iostream>
#include<vector>
#include<queue>

#define point pair<int,int>

using namespace std;

struct Node{
    point pos;
    int cost;
    int steps_available;
    point dir;
};

vector<point> dirs ={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1},
};

bool out_of_bound(point p, int n, int m){
    return p.first < 0 || p.first >= n || p.second < 0 || p.second >= m;
}

int main(){
    int n,m; cin >> n >> m;
    vector<string> grid(n);
    point s,t;
    int nodeAvailable = 2;
    for (int i = 0; i < n; i++){
        cin >> grid[i];
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'S')
                s = {i,j};
            else if (grid[i][j] == 'T')
                t = {i,j};
            else if (grid[i][j] == '.')
                nodeAvailable++;
    }
    

    vector<vector<vector<vector<bool>>>> visited(3,vector<vector<vector<bool>>>(4, vector<vector<bool>>(n,vector<bool>(m,false)))); 
    vector<queue<Node>> vq(211114);
    vq[0].push({s,0,2,{0,0}});
    // q.push();
    // int cost = -1;

    for (int cost = 0; cost < vq.size(); cost++){
        int size = vq[cost].size();
        while (size--){
            auto curr = vq[cost].front();
            vq[cost].pop();
            if (out_of_bound(curr.pos,n,m))
                continue;
            
            if (grid[curr.pos.first][curr.pos.second] == '#')
                continue;
            int temp = 0;
            for (int i = 0; i < 4; i++)
                if (dirs[i] == curr.dir){
                    temp = i;
                    break;
                }

                
            if (visited[curr.steps_available][temp][curr.pos.first][curr.pos.second])
                continue;

            if (curr.pos == t){
                cout << curr.cost;
                return 0;
            }

            // grid[curr.pos.first][curr.pos.second] = '#';
            if (temp != -1)
                visited[curr.steps_available][temp][curr.pos.first][curr.pos.second] = true;

            for (auto dir : dirs){
                if (dir == curr.dir){
                    if (curr.steps_available == 0){
                        vq[curr.cost + 3].push({{curr.pos.first + dir.first, curr.pos.second + dir.second}, curr.cost + 3,1,dir});
                    }else{
                        vq[curr.cost + 1].push({{curr.pos.first + dir.first, curr.pos.second + dir.second}, curr.cost + 1,curr.steps_available - 1,dir});
                    }
                }else{
                    vq[curr.cost + 1].push({{curr.pos.first + dir.first, curr.pos.second + dir.second}, curr.cost + 1,2,dir});
                }
            }
        }
    }

    cout << -1;

}