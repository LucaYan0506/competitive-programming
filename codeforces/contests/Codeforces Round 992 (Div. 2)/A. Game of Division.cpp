#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int t; cin >> t;
    vector<string> res;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        bool gotAnswer = false;
        for (int i = 0; i < a.size(); i++){
            bool flag = true;
            for (int j = 0; j < a.size(); j++){
                if (i == j)
                    continue;
                
                if (abs(a[i] - a[j]) % k == 0){
                    flag = false;
                    break;
                }
            }

            if (flag){
                res.push_back("YES");
                res.push_back(to_string(i + 1));
                gotAnswer = true;
                break;
            }
        }

        if (!gotAnswer)
            res.push_back("NO");

    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}