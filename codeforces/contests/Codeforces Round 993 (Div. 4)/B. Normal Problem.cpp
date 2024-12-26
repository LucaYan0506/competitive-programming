#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t; cin >> t;
    vector<string> res;
    while(t--){
        string s; cin >> s;
        string ans = "";

        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == 'p')
                ans += 'q';
            else if (s[i] == 'q')
                ans += 'p';
            else
                ans += 'w';
        }

        res.push_back(ans);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}
