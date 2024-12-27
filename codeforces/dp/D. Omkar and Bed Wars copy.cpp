#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include <fstream>

using namespace std;

bool threeConsecutive(int l,  string s){
    int n = s.size();
    return s[l % n] == s[(l + 1) % n] &&  s[(l + 1)%n] == s[(l + 2)%n];
}

int main(){
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n; cin >> n;
        string s;cin >> s;
        int l = 0, r = n -1;
        bool flag = false;//wrap around case
        while(s[l] == s[r]){
            r--;
            if (l == r){
                flag = true;
                break;
            }
            
        }
        if (flag){
            int count2 = 0;
            if(n % 3 == 0)
                count2 = n / 3;
            else
                count2 = n / 3 + 1;
            
            res.push_back(count2);
            continue;
        }
        if (r != n - 1){
            string temp = s;
            s = temp.substr(r + 1,n - r);
            s += temp.substr(0,r + 1);
        }
        int count = 1;
        int ans = 0;
        for (int i = 0; i < n - 1; i++){
            if (s[i] == s[i + 1])
                count++;
            else{
                ans += count / 3;
                count = 1;
            }
        }
        ans += count / 3;
        res.push_back(ans);
    }

    for (auto x : res)
        cout << x << endl;




    return 0;
}


/*
 2     4       4          4          4        3     0    3
LLLL                   RRRRRRRRLLLLLLLLLLRRRRRRRRRLRRRRRRRRRRLLLLLLLRRLLLLLLLRRRRLLLLLLLRRRRRRRRRLLLLLLRRLLLLLLLRRLLRRRRRRLLLLRRRRRRRRRRLLRRRRLLLR
LLLLLRRRRRRRRRLLLLLLLLLL == 10
RRRRRRRRRLRRRRRRRRRR

 */