#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(21,vector<bool>(21,false));
        dp[0][0] = true;

        for (int i = 1; i <= p.size(); i++){
            for (int j = 1; j <= s.size(); j++){
                if (p[i - 1] == s[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*' && p[i - 2] == '.')
                    return dp[j - 1][j - 1];
                else if(p[i - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[i - 1] == '*')
                    dp[i][j] = dp[i - 2][j - 1] || dp[i][j - 1] ;
                else
                    dp[i][j] = false;
                
            }
        }

        return dp[p.size()][s.size()];
    }
};

int main(){
    Solution sol = Solution();
    cout << sol.isMatch("mississippi","mis*is*p*.");



    return 0;
}
