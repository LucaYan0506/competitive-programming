#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        pair<int,int> res = {0,0}; // j i

        for (int i = 0; i < n ; i++){
            for (int j = i; j >= 0; j--){
                if (j == i){
                    dp[i][j] = true;
                }
                else if (i - j == 1){
                    if (s[i] == s[j]){
                        dp[i][j] = true;
                        if (i - j > res.second - res.first)
                            res = {j,i};
                    }
                }else if (s[i] == s[j] && dp[i - 1][j + 1] &&  dp[i - 1][i - 1]){
                    dp[i][j] = true;
                        if (i - j > res.second - res.first)
                            res = {j,i};
                }
            }
        }

        return s.substr(res.first, res.second - res.first + 1);
    }
};

int main(){
    Solution sol;
    cout << sol.longestPalindrome("cbbd");

    return 0;
}