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

int bs1(vector<int32_t>& nums, int goal) {
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

int bs2(vector<int32_t>& nums, int goal) {
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
    vector<int32_t> res;
    while(t--){
        int n,x,y; cin >> n >> x >> y;
        vector<int32_t> keys;
        map<int32_t,int32_t> freq;
        int tot = 0;
        for (int i = 0; i < n; i++){
            int32_t temp; cin >> temp;
            freq[temp]++;
            tot += temp;
            keys.push_back(temp);
        }

        sort(keys.begin(),keys.end());
        auto it = unique(keys.begin(), keys.end());
        keys.erase(it, keys.end());
        int ans = 0;
        while(keys.size()){
            int currTot = tot - keys.back();
            
            int high = bs1(keys,currTot - x);
            int low = bs2(keys,currTot - y);
            
            if (high >= keys.size() || high < 0 || low >= keys.size() || low < 0){
                keys.pop_back();
                continue;
            }
            high = keys[high];
            low = keys[low];
            
            int count = 0;
            for (int i = low; i <= high; i++)
                if (i != keys.back())
                    count += freq[i];
            
            ans += count * freq[keys.back()];
            if (keys.back() >= low && keys.back() <= high)
                ans += (freq[keys.back()] * (freq[keys.back()] - 1) / 2); 

            keys.pop_back();
        }

        res.push_back(ans);
        freq.clear();
        // delete &freq;
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}