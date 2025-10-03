//#include <iostream>
//#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n, w, dp[5005], lens[5005], glob_prv[5005], prv[5005];
string s[5005];

bool check(int mid){
    dp[n] = 0; prv[n] = n;
    for (int i = n-1; i >= 0; i--){
        int max_sofar = 0;
        dp[i] = 2e9;
        for (int j = i; j <= i+mid-1 && j+1 <= n; j++){
            max_sofar = max(max_sofar, lens[j]);
            if (max_sofar+1 + dp[j+1] < dp[i]) {
                dp[i] = max_sofar+1 + dp[j+1];
                prv[i] = j+1;
            }
        }
    }
    return dp[0] <= w+1;
}

void solve(){
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s+n);
    for (int i = 0; i < n; i++) lens[i] = s[i].size();

    int l = 0, r = 5005, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            for (int i = 0; i <= n; i++) glob_prv[i] = prv[i];
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    vector<vector<string>> print;
    vector<int> cols;
    for (int i = 0; i != glob_prv[i]; i = glob_prv[i]){
        int mx = 0;
        for (int j = i; j < glob_prv[i]; j++){
            mx = max(mx, lens[j]);
        }
        cols.push_back(mx);
        mx++;
        print.emplace_back();
        for (int j = i; j < glob_prv[i]; j++){
            string pad(mx - lens[j], ' ');
            print.back().push_back(s[j] + pad);
        }
        string pad(mx, ' ');
        while (print.back().size() < ans) print.back().push_back(pad);
    }
    cout << ans << ' ' << cols.size() << endl;
    for (auto u: cols) cout << u << ' ';
    cout << endl;

    for (auto& u: print) reverse(u.begin(), u.end());
    for (int i = 0; i < ans; i++){
        for (auto& u: print) {
            cout << u.back();
            u.pop_back();
        }
        cout << endl;
    }




}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}