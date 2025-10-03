#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

static bool cmp(int a, int b){
    return a > b;
}

vector<long long> res;

void helper(){
    int n,k; cin >> n >> k;
    vector<long long> bottle(k + 1); //bottle[index] = tot cost

    for (int i = 0; i < k; i++){
        long long bi,ci; cin >> bi >> ci;
        bottle[bi] += ci;
    }

    sort(bottle.begin(), bottle.end(), cmp);
    long long ans = 0;
    for (int i = 0; i < k && n > 0; i++, n--)
        ans += bottle[i];
    

    res.push_back(ans);
}

int main(){
    int t; cin >> t;

    for (int i = 0; i < t; i++)
        helper();

    for (const int x : res)
        cout << x << endl;


    return 0;
}