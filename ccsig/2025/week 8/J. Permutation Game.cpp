#include<iostream>
#include<vector>


using namespace std;
vector<int> dp;
vector<int> a;

void helper(int i){
    int size = dp.size();
    if (i < 0 || i >= size)
        return;

    if (dp[i] != -1)
        return;



        
    for (int j = 1; i - a[i]*j >=0; j++){
        if (a[i] >= a[i - a[i]*j])
            continue;

        helper(i - a[i]*j);
        if (dp[i - a[i]*j] == 0)
            dp[i] = 1;
    }

    if (a[i] == 6)
        cout << "";

    for (int j = 1; i + a[i]*j < size; j++){
        if (a[i] >= a[i + a[i]*j])
            continue;

        helper(i + a[i]*j);
        if (dp[i + a[i]*j] == 0)
            dp[i] = 1;
    }

    if (a[i] == 6)
        cout << "";

    if (dp[i] == -1)
        dp[i] = 0;
}

int main(){
    int n; cin >> n;
    a = vector<int>(n);
    int start = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1)
            start = i;
    }

    dp = vector<int>(n,-1); //-1=unexplored 1=player that play the turn win, 0=opposite player win
    helper(start);

    for (int i = 0; i < dp.size(); i++)
        if (dp[i] == 1)
            cout << "A";
        else
            cout << "B";


    return 0;
}