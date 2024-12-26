#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <cstdint>
#include <cmath>   

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int32_t main(){
    int t; cin >> t;
    vector<vector<int>> res;
    while(t--){
        int n; int k; cin >> n >> k;
        if (k > pow(2,n - 1)){
            res.push_back({-1});continue;
        }

        vector<int> ans(n);
        int left = 0, right = n - 1;
        int i = 1;
        while(i <= n){
            if (k <= pow(2,right - left - 1)){
                ans[left] = i;
                i++; left++;
            }else{
                ans[right] = i;
                k -= pow(2,right - left -1);
                i++; right--;
            }
        }
        
        res.push_back(ans);

    }

    for (auto x : res){
        for (int i : x)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}