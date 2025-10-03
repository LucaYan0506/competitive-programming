#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n; int k; cin >> n; cin >> k;
    vector<int> h(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= n; i++)
        h[i] += h[i - 1];

    int res = INT_MAX;  
    int j = 0;
    for (int i = 1; i <= n - k + 1; i++){
        if (res > h[i + k - 1] - h[i - 1]){
            res = h[i + k - 1] - h[i - 1];
            j = i;
        }
    }

    cout << j;

    return 0;
}


/*
7 3
1 2 6 5 1 1 1

*/