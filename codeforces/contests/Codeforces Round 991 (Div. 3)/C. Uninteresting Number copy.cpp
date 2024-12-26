#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t; cin >> t;
    vector<string> res;

    while(t--){
        string str; cin >> str;
        vector<int> nums = {0};
        for (char c : str){
            int n = c - '0';
            sort(nums.begin(), nums.end());
            nums.erase(unique(nums.begin(), nums.end()), nums.end());
            int size = nums.size();
            for (int i = 0; i < size; i++){
                if (n == 2 || n == 3)
                    nums.push_back((nums[i] + n * n) % 9);
                nums[i] = (nums[i] + n) % 9;
            }
        }
        bool flag = false;
        for (int x : nums){
            if (x == 0){
                flag = true;
                break;
            }
        }
        if (flag)
            res.push_back("YES");
        else
            res.push_back("NO");
        
    }

    for (auto x : res)
        cout << x << endl;
    return 0;
}