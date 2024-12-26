#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t; cin >> t; 
    vector<int> results;
    while(t--){
        int n,m; cin >> n >> m;
        int res = 0;
        bool flag = true;
        for (int i = 0; i < n; i++){
            string temp; cin >> temp;
            if (temp.size() <= m && flag){
                m -= temp.size(); 
                res++;
            }else
                flag = false;

        }

        results.push_back(res);
    }

    for (int x : results)
        cout << x << endl;
    return 0;
}