#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> a (1 << n / 2, vector<int>(2)); //a[i][0] = length of a[i]; a[i][1] = tot(a)
        vector<vector<int>> b (1 << (n + 1) / 2, vector<int>(2)); 
        
        int totL = 0;
        for (int i = 0; i < n; i++)
            totL += nums[i];
        
        for (int mask = 1; mask < 1 << n / 2; mask++)
            for (int i = 0; i < n / 2; i++)
                if (mask & 1 << i){
                    a[mask][0]++;
                    a[mask][1] += nums[i];
                }

        for (int mask = 1; mask < 1 << (n + 1) / 2; mask ++)
            for (int i = n / 2; i < n; i++)
                if (mask & 1 << (i - n / 2)){
                    b[mask][0]++;
                    b[mask][1] += nums[i];
                }

        vector<unordered_set<int>> b_set ((n + 1) / 2 + 1);
        for (int i = 0; i < b.size(); i++)
            b_set[b[i][0]].insert(b[i][1] * n);
        

        sort(b.begin(), b.end(), cmp);
        for (int i = 0; i < a.size(); i++){
            for (int j = 1; j < b_set.size(); j++){
                if (a[i][0] + j < n && b_set[j].count(totL * (a[i][0] + j) - a[i][1] * n))
                    return true;
            }
        }

        return false;
    }
};

int main(){
    Solution sol; 
    vector<int> nums = {8,6,7,7,2};
    cout << sol.splitArraySameAverage(nums);







}