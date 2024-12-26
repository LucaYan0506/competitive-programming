#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int average(vector<int> arr){
    long long tot = 0;
    for (int x : arr)   
        tot += x;

    return tot / arr.size();
}

bool check(vector<int> arr){
    long long tot = 0;
    for (int x : arr)   
        tot += x;

    return tot % arr.size() == 0;
}

int main(){
    int t; cin >> t;
    vector<string> res;
    while (t--){
        int n; cin >> n;
        vector<int> arr1;
        vector<int> arr2;
        bool flag = true;
        for (int i = 0; i < n; i++){
            int temp; cin >> temp;
            if (flag)
                arr1.push_back(temp);
            else
                arr2.push_back(temp);

            flag = !flag;
        }

        if (check(arr1) && check(arr2) && average(arr1) == average(arr2))
            res.push_back("YES");
        else
            res.push_back("NO");
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}