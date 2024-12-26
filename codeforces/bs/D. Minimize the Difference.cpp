#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <cstdint>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int sum(vector<int> &a){
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i];

    return res;
}

int avg(vector<int> &a){
    return sum(a) / a.size();
}

int bsmx(vector<int> &a){
    int l = avg(a), r = sum(a);

    while(l < r){
        int mid = (r + l)/2;
        int extra = 0;

        for (int i = 0; i < a.size(); i++)
            extra =  MAX(0,extra) + (a[i] - mid);
        
        if (extra > 0)
            l = mid + 1;
        else    
            r = mid;
    }

    return l;
}

int bsmn(vector<int> &a){
    int l = 0, r = a[0];

    while(l <= r){
        int mid = (r + l)/2;
        int extra = 0;

        for (int i = 0; i < a.size(); i++){
            extra += (a[i] - mid);
            if (extra < 0)
                break;
        }
        
        if (extra >= 0)
            l = mid + 1;
        else    
            r = mid - 1;
    }

    return r;
}

int32_t main(){
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int mx = bsmx(a),mn = bsmn(a);
        res.push_back(mx - mn);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}