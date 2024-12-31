#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}


int32_t main(){
    fastIO();
    int t; cin >> t;
    vector<char> res;
    while(t--){
        int n; cin >> n;
        map<char,int> freq;
        for (int i = 0; i < 2*n; i++){
            string temp; cin >> temp;
            for (auto c : temp){
                freq[c]++;
            }
        }
        string temp; cin >> temp;
        for (auto c :temp)
            freq[c]++;

        for (auto x : freq){
            if (x.second % 2 == 1){
                res.push_back(x.first);
                break;
            }
        }
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}