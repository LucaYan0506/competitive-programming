#include<iostream>
#include<vector>
#include<map>
#include<algorithm> 
#include<cmath>


using namespace std;

int lowbit(int n){
    int res = 1;

    while((n & res) == 0)
        res = res << 1;
    

    return res;
}

int main(){
    int sum; cin >> sum;
    int limit; cin >> limit;

    
    vector<vector<int>> nums(limit + 1);

    for (int i = 1; i <= limit; i++)
        nums[lowbit(i)].push_back(i);
    

    vector<int> res;
    for (int i = nums.size() - 1; i >= 0; i--){
        for (int j = 0; j < nums[i].size(); j++){
            if (sum < i){
                break;
            }
            sum -= i;
            res.push_back(nums[i][j]);
        }
    }    

    if (sum != 0){
        cout << "-1";
        return 0;
    }

    cout << res.size() << endl;
    for (int x : res)
        cout << x << " ";


    return 0;
}