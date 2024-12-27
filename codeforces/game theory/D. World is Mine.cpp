#include<bits/stdc++.h>

// #define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}


int32_t main(){
    fastIO();
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n; cin >> n;
        int distinct_cake_n = 0;
        vector<int> freq(5001,0);
        vector<set<int>> freq_inverse(5001);
        for (int i = 0; i < n; i++){
            int temp; cin >> temp;
            if (freq[temp] == 0)
                distinct_cake_n++;
            freq[temp]++;
        }

        for (int i = 0; i < 5001; i++)
            if (freq[i] > 0)
                freq_inverse[freq[i]].insert(i);
        
        int maxi = 0;
        int cakeAvailable = 0;
        for (int i = 1; i < 5001; i++){
            if (freq[i] == 0)
                continue;
            cakeAvailable++;
            freq_inverse[freq[i]].erase(freq_inverse[freq[i]].find(i));
            auto freq_inverse2 = freq_inverse;
            int count = cakeAvailable;
            int localMaxi = 0;
            for (int j = 1; j <= cakeAvailable && count >= 0; j++){
                while (freq_inverse2[j].size() > 0 && count - j >= 0){
                    freq_inverse2[j].erase(--freq_inverse2[j].end());
                    count-= j;
                    localMaxi++;
                }
            }
            maxi = max(maxi,localMaxi);

        }
        res.push_back(distinct_cake_n - maxi);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}