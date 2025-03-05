#include<bits/stdc++.h>

// #define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()

const int mod = 1e9+7;
using namespace std;

vector<int> SieveOfEratosthenes(int n){
    vector<bool> isPrime(n + 1, true);
    for (int p = 2; p * p <= n; p++) 
        if (isPrime[p] == true) 
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;

    vector<int> primes;
    FOR(i,2, n + 1)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

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

void solve(){
    int n,w; cin >> n >> w;
    w++; //consider the blank space at end
    vector<string> s(n);
    FOR(i,0,n)
        cin >> s[i];
    
    int r = bs(s,w);
    vector<int> newSplitAt = findNewSplitAt(s,r);
    vector<int> a;
    int prev = 0;
    for (int x : newSplitAt){
        int maxi = 0;
        FOR(i,prev,x + 1)
            maxi = MAX(maxi, s[i].size());
        a.push_back(maxi);
        prev = x + 1;
    }
    int c = a.size();

    cout << r << " " << c << endl;
    for(int x : a)
        cout << x << " ";
    cout <<  endl;

    int newSplitAtCopy[newSplitAt.size()];
    newSplitAtCopy[0] = 0;
    FOR(i,0,newSplitAt.size() - 1)
        newSplitAtCopy[i + 1] = newSplitAt[i] + 1;
    
    FOR(j,0,r){
        if (j > 0)
            cout << endl;
        FOR(i,0,newSplitAt.size()){
            auto x = newSplitAtCopy[i];
            if (x > newSplitAt[i]){//this column already reached the last elem
                FOR(k,0,a[i] + 1)
                    cout << " ";
                continue;
            }
            cout << s[x];
            FOR(k,0,a[i] - s[x].size() + 1)
                    cout << " ";
            
            newSplitAtCopy[i]++;
        }
    }
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}