#include<bits/stdc++.h>

using namespace std;

int log(int n){
    int res = 0;
    while(n / 2 > 0)
        res++, n /= 2;

    return res;
}

vector<vector<int>> makeSparseTable(vector<int> init){
    int n = init.size();
    vector<vector<int>> sparseTable(n,vector<int>(log(n) + 1,1));

    for (int i = 0; i < n; i++)
        sparseTable[i][0] = init[i];


    for (int j = 1; j <= log(n); j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            sparseTable[i][j] = __gcd(sparseTable[i][j - 1],sparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }


    return sparseTable;
}

/*
int l,r; cin >> l >> r; // querry
int k = log(r - l + 1); // range distance
int temp = __gcd(sparseTable[l][k],sparseTable[r - (1 << k) + 1][k]); // get gcd of that range
*/