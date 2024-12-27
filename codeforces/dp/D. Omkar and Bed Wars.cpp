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
        n = s.size();
        int l = 0;
        int count = 0;
        while(l < n){
            if (threeConsecutive(l,s)){
                if (s[(l + 1) % n] == 'L')
                    s[(l + 1) % n] = 'R';
                else
                    s[(l + 1) % n] = 'L';

                count++;
            }
            l += 2;
        }
        res.push_back(count);
        
    }

    for (auto x : res)
        cout << x << endl;




    return 0;
}


/*

 */