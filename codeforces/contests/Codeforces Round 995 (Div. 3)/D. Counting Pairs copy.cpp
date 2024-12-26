#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <map>
#include <cstdint>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int bs1(vector<int>& nums, int goal) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == goal)
            return mid;
        else if (nums[mid] < goal)
            left = mid + 1;
        else
            right = mid - 1;
    }
 
    if (left < n && nums[left] - goal < 0)
        return left;
    return left - 1;
}

int bs2(vector<int>& nums, int goal) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == goal)
            return mid;
        else if (nums[mid] < goal)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (left < n && nums[left] - goal > 0)
        return left;
    return left + 1;
}

int32_t main(){
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n,x,y; cin >> n >> x >> y;
        vector<int> a(n);
        int tot = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            tot += a[i];
        }

        sort(a.begin(),a.end());

        int ans = 0;
        while(a.size()){
            int currTot = tot - a.back();
            a.pop_back();
            
            int high = bs1(a,currTot - x);
            int low = bs2(a,currTot - y);
            
            if (high >= a.size() || high < 0 || low >= a.size() || low < 0)
                continue;
            while(high + 1 < a.size() && a[high] == a[high + 1])
                high++;
            while(low - 1 >= 0 && a[low] == a[low - 1])
                low--;

            ans += (high - low + 1);
        }

        res.push_back(ans);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}