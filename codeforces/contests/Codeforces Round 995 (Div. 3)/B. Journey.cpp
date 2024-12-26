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
        int n,a,b,c; cin >> n >> a >> b >> c;
        int tot = a + b + c;
        int days = (n / tot) * 3;
        if (n % tot == 0)
            days;
        else if (n % tot <= a)    
            days += 1;
        else if (n % tot <= a + b)
            days += 2;
        else if (n % tot < a + b + c)
            days += 3;

        
        res.push_back(days);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}