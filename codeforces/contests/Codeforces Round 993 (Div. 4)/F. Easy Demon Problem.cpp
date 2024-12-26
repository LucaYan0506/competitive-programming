#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

bool bs(vector<pair<int,int>>& nums, int goal, int ai) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid].first + ai * nums[mid].second == goal)
            return true;
        else if (nums[mid].first + ai * nums[mid].second < goal)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false;
}

static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    int n,m,q; cin >> n >> m >> q;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> aSum(n);
    vector<pair<int,int>> bSum(m);
    int totSum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            aSum[i] += a[i] * b[j];
            bSum[j] = {bSum[j].first + a[i] * b[j], b[j]}; 
            totSum += a[i] * b[j];
        }

    sort(bSum.begin(),bSum.end(),cmp);
    vector<string> res;
    for (int k = 0; k < q; k++){
        int query; cin >> query;
        bool flag = false;
        for (int i = 0; i < n; i++){
            if (bs(bSum, totSum - aSum[i] - query, a[i])){
                flag = true;
                res.push_back("YES");
                break;
            }
        }


        if (!flag)
            res.push_back("NO");
    }

    for (auto x : res)
        cout << x << endl;
    return 0;
}