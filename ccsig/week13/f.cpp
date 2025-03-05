#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

<<<<<<< HEAD
int dpWeight(vector<string>& nums, int k){
    vector<int> dp(nums.size());
    dp[0] = nums[0].size() + 1;
    FOR(i,1,k)
        dp[i] = MAX(dp[i - 1], nums[i].size() + 1);
    
    FOR(i,k,nums.size()){
        dp[i] = nums[i].size() + dp[i - 1] + 1;
        int maxi = nums[i].size() + 1;
        FOR(j,1,k){
            maxi = MAX(nums[i - j].size() + 1,maxi);
            dp[i] = min(dp[i],maxi + dp[i - j - 1]);
        }
    }

    return dp[dp.size() - 1];
}

vector<int> findNewSplitAt(vector<string>& nums, int k){
    int n = nums.size();
    vector<int> dp(n);
    vector<int> splitAt(n);
    dp[0] = nums[0].size() + 1;
    splitAt[0] = -1;

    FOR(i,1,k)
        dp[i] = MAX(dp[i - 1], nums[i].size() + 1),
        splitAt[i] = -1;
    

    FOR(i,k,nums.size()){
        dp[i] = nums[i].size() + dp[i - 1] + 1;
        splitAt[i] = i - 1;

        int maxi = nums[i].size() + 1;
        FOR(j,1,k){
            maxi = MAX(nums[i - j].size() + 1,maxi);
            if (maxi + dp[i - j - 1] < dp[i]){
                dp[i] = maxi + dp[i - j - 1];
                splitAt[i] = i - j - 1;
            }
        }
    }

    vector<int> newSplitAt;
    int t = n - 1;
    while(t != -1){
        newSplitAt.push_back(t);
        t = splitAt[t];
    }

    reverse(all(newSplitAt));
    return newSplitAt;
}

int bs(vector<string>& nums, int goal) {
    int n = nums.size();
    int l = 0, r = n;

    while(l < r){
        int m = (l + r) / 2;
        int w = dpWeight(nums, m);
        if (w < goal){
            r = m;
        }
        else if (w == goal)
            return m;
        else 
            l = m + 1;
    }

    return r;
}

=======
>>>>>>> b8c229813270b59131daf7ed34b1ec8b1eff2927
void solve(){
    // FOR(i,5, 25)
    //     cout << i << " = " << (i*i - i) / 2 << " " << ((i*i - i) / 2) % i <<  endl;

    int n, p; cin >> n >> p;
    n;
    int count = 1;
    vector<int> edges(n + 1);
    set<pair<int,int>> visited;
    int start = 0;
    int end = start + count;
    visited.insert({start,end});
    FOR(i,0, 2*n + p){
        cout << start + 1 << " " << end + 1 << endl;
        
        start = end;
        end = (start + count) % n;
        if (visited.count({start,end})){
            if ((i + 1) % n == 0){
                count++;
                start = 0;
            }else{
                start++;
            }
            end = (start + count) % n;
            visited.insert({start,end});
            visited.insert({end,start});
        }
    }
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}