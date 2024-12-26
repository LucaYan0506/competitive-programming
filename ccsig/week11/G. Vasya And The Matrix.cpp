#include<iostream>
#include<vector>

using namespace std;

int xorList(vector<int> a){
    int res = 0;

    for (int x : a)
        res ^= x;

    return res;
}

int main(){
    int n,m; cin >> n >> m;
    vector<int> rows(n);
    vector<int> columns(m);
    for (int i = 0; i < n; i++)
        cin >> rows[i];

    for (int i = 0; i < m; i++)
        cin >> columns[i];

    if (xorList(rows) != xorList(columns)){
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    vector<vector<int>> mat(n,vector<int>(m,0));
    //row
    for (int i = 0; i < n - 1; i++)
        mat[i][0] = rows[i];
    
    //col
    for (int j = 1; j < m; j++)
        mat[n - 1][j] = columns[j];
    
    mat[n-1][0] = rows[n - 1];
    mat[n-1][0] = xorList(mat[n-1]);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
    
        cout << endl;
    }



    return 0;
}