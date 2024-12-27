#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}

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


int32_t main(){
    fastIO();
    int t; cin >> t;
    vector<string> res;
    while(t--){
        int n,q; cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        vector<int> diff;
        for (int i = 1; i < n; i++)
            diff.push_back(abs(a[i] - a[i - 1]));

        auto sparseTable = makeSparseTable(diff);
        string ans = "";
        
        for (int i = 0; i < q; i++){
            int l,r; cin >> l >> r;
            if (l == r){
                ans += "0 ";
                continue;
            }
            l--,r-=2;
            if (r < l){
                ans += "0 ";
                continue;
            }
            int k = log(r - l + 1);
            int temp = __gcd(sparseTable[l][k],sparseTable[r - (1 << k) + 1][k]);
            ans += to_string(temp) + " ";
        }
        res.push_back(ans);
    }

    for (auto x : res)
        cout << x << endl;

   
    return 0;
}