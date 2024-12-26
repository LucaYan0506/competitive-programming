#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        for (int a = 1; a < n; a++){
            for (int b = 1; b < n; b++){
                if (a + b == n)
                    ans++;
            }
        }

        res.push_back(ans);
    }

    for (auto x : res)
        cout << x << endl;
    return 0;
}