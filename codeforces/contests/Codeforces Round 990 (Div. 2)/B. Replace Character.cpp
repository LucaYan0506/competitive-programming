#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

// vector<string> permutations(string str,vector<bool>&used){
//     int n = str.size();
//     vector<string> res;

//     for (int i = 0; i < n; i++){
//         if (used[i])
//             continue;
//         used[i] = true;
//         vector<string> temp = permutations(str,used);
//         if (temp.size() == 0){
//             string a (1,str[i]);
//             res.push_back(a);
//         }else{
//             for (string s : temp)
//                 res.push_back(str[i] + s);
//         }

//         used[i] = false;    
//     }

//     return res;
// }

// int main(){
//     string test = "aaabba";
//     set<string> set_;
//     vector<bool> used(test.size(),false);
//     vector<string> temp = permutations(test,used);
    
//     for (string s : temp)
//         set_.insert(s);

//     int index = 0;
//     for (auto s : set_) 
//         cout << ++index << " "<< s << endl;
// }


static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}


int main(){
    int t; cin >> t;
    vector<string> res;
    
    while(t--){
        vector<pair<int,int>> freq(26,{0,0});
        int n; cin >> n;
        string s; cin >> s;

        for (char c : s)
            freq[c - 'a'] = {c - 'a', freq[c - 'a'].second + 1};

        sort(freq.begin(),freq.end(), cmp);
        
        int least = -1, most = freq[25].first;
        for (int i = 0; i < 26; i++){
            if (freq[i].second == 0)
                continue;
            least = freq[i].first;
            break;
        }

        for (int i = 0; i < n; i++){
            if (s[i] == (least + 'a')){
                s[i] = (most + 'a');
                break;
            }
        }

        res.push_back(s);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}