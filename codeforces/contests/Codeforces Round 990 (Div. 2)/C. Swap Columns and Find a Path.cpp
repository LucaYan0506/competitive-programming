#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t; cin >> t;
    vector<int> results;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> a(2, vector<int>(n)); 
        for (int i = 0; i < n; i++)
            cin >> a[0][i];
       for (int i = 0; i < n; i++)
            cin >> a[1][i];


        int res = 0;
        vector<int> unchosen;
        for (int i = 0; i < n; i++){
            if (a[0][i] > a[1][i]){
                res += a[0][i];
                unchosen.push_back(a[1][i]);
            }else{
                res += a[1][i];
                unchosen.push_back(a[0][i]);
            }
        }
        
        int maxV = INT_MIN;
        for (int x : unchosen)
            maxV = max(maxV,x);
        res += maxV;
        results.push_back(res);
    }

    for (auto x : results)
        cout << x << endl;
    return 0;
}

