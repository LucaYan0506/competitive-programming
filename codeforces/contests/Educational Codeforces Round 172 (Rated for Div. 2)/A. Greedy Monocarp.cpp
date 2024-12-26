#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> res;

bool static cmp(int a, int b){
    return a > b;
}

void minNumberCoins(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(),a.end(),cmp);

    int tot = 0;
    for (int x : a){
        tot += x;
        if (tot > k){
            tot -= x;
            break;
        }
    }

    res.push_back(k - tot);
}

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        minNumberCoins();

    for (int x : res)
        cout << x << endl;



    return 0;
}