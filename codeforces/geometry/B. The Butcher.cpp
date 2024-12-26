#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}
pair<int,int> helper(multiset<pair<int,int>> &s_a,multiset<pair<int,int>> &s_b){
    int height = (--s_a.end())->first;
    int base = 0;
    while(!s_a.empty() && ((--s_a.end())->first) == height){
        auto curr = *--s_a.end();
        base += curr.second;
        s_a.erase(s_a.find(curr));
        swap(curr.first,curr.second);
        s_b.erase(s_b.find(curr));
    }

    if (s_a.size() > 0){
        auto temp = helper(s_b,s_a);
        swap(temp.first,temp.second);
        if (temp.first == -1 || temp.first != height)
            return {-1,-1};
        base += temp.second;
    }


    return {height,base};
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    vector<string> res;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> rects(n);
        multiset<pair<int,int>> s_a;
        multiset<pair<int,int>> s_b;
        
        int totA = 0;
        for (int i = 0; i < n; i++){           
            int a,b; cin >> a >> b;
            s_a.insert({a,b});
            s_b.insert({b,a});
            rects[i] = {a,b};
            totA += a*b;
        }
        set<pair<int,int>> ans;
        auto temp = helper(s_a,s_b);
        if (temp.first != -1)
            ans.insert(temp);

        s_a.clear();
        s_b.clear();
        for (int i = 0; i < n; i++){           
            auto [a,b] = rects[i];
            s_a.insert({a,b});
            s_b.insert({b,a});
        }
        temp = helper(s_b,s_a);
        swap(temp.first, temp.second);
        if (temp.first != -1)
            ans.insert(temp);

        res.push_back(to_string(ans.size()));
        for (auto x : ans)
            res.push_back(to_string(x.first) + " " + to_string(x.second));

    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}