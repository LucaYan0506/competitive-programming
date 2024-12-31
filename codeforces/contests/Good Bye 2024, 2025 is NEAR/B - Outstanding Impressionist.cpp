#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); 
}

int bs(vector<int>& nums, int goal) {
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

    if (right >= 0 && nums[right] < goal)
        return right;
    return left;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> range(n);
        map<int,int> freq;
        vector<int> freq_keys;
        for (int i = 0; i < n; i++){
            cin >> range[i].first >> range[i].second;
            if (range[i].first == range[i].second){
                freq[range[i].first]++;
                freq_keys.push_back(range[i].first);
            }
        }

        sort(freq_keys.begin(),freq_keys.end());
        auto it = unique(freq_keys.begin(), freq_keys.end());
        freq_keys.erase(it,freq_keys.end());
        
        for (auto [l,r] : range){
            if (l == r){
                if (freq[l] > 1)
                    cout << "0";
                else
                    cout << "1";
                continue;
            }
            int uniqueL;
            if (freq.count(l)){
                uniqueL = bs(freq_keys,l);
            }
            else
                uniqueL = bs(freq_keys,l) + 1;

            int uniqueR = bs(freq_keys,r) + 1;
            
            if (r - l + 1 > uniqueR - uniqueL)
                cout << "1";
            else 
                cout << "0";
        }
        cout << endl;
    }

    return 0;
}