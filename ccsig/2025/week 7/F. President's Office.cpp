#include<iostream>
#include<vector>

using namespace std;

int res = 0;

void dfs(vector<vector<char>> &grid, int i, int j, char c, bool president = false){
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return;

    if (grid[i][j] == '.')
        return;

    if (grid[i][j] == c){
        grid[i][j] = '.';
        dfs(grid,i + 1,j,c, president);
        dfs(grid,i - 1,j,c, president);
        dfs(grid,i,j + 1,c, president);
        dfs(grid,i,j - 1,c, president);
    }else if (president){
        res++;
        dfs(grid,i,j,grid[i][j], false);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n; cin >> m;
    char c; cin >> c;
    pair<int,int> startPoint;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> grid[i][j]; 
            if (grid[i][j] == c)
                startPoint = {i,j};
        }

    dfs(grid, startPoint.first, startPoint.second, c, true);
    cout << res;

    return 0;
}