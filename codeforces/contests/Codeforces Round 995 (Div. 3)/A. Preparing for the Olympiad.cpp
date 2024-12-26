#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <cstdint>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int32_t main(){
    int t; cin >> t;
    vector<int> res;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int sum = 0;
        for (int i = 0; i < n - 1; i++){
            if (a[i] > b[i + 1])
                sum += a[i] - b[i + 1];
        }

        sum += a[n - 1];
        res.push_back(sum);

    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}