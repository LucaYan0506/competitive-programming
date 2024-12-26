#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t; cin >> t;
    vector<string> res;

    while(t--){
        string str; cin >> str;
        vector<bool> check(9,false);
        check[0] = true;
        for (char c : str){
            int n = c - '0';
            vector<bool> curr = check;
            for (int i = 0; i < curr.size(); i++){
                if (curr[i]){
                    check[i % 9] = false;
                    check[(i + n) % 9] = true;
                    if (n == 3 || n == 2)
                        check[(i + n*n) % 9] = true;
                }
            }
        }

        if (check[0])
            res.push_back("YES");
        else
            res.push_back("NO");
    }

    for (auto x : res)
        cout << x << endl;
    return 0;
}