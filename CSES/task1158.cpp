// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// int rec(vector<pair<int,int>>& book,int i, bool take, int remain, int pages = 0){
//     if (take){
//         remain -= book[i].first;
//         pages += book[i].second;
//     }

//     if (remain < 0)
//         return INT_MIN;

//     if (i == n - 1)//if it's the last book
//         return pages;

//     return max(rec(book, i + 1,true, remain,pages),rec(book, i + 1, false, remain,pages));
// }

int main() {
    int n,x; cin >> n; cin >> x;
    
    vector<pair<int,int>> book(n + 1); //book[i].first == cost   book[i].first == page
    //book[0] is empty

    for(int i = 1; i < n + 1; i++){
        int temp; cin >> temp;
        book[i] = {temp,0};
    }
        
    for (int i = 1; i < n + 1; i++){
        int temp;cin >> temp;
        book[i].second = temp;
    }
    
    //sort(begin(book),end(book),cmp);

    //cout << rec(book,-1,false,x);
    // vector<pair<int,int>> dp(n+1);//dp[i].first = remain cost, dp[j].second = pages
    // dp[0] = {x,0};
    // pair<int,int> bestSol = dp[0];
    
    // for (int i = 1; i < n + 1; i++){
    //     if (book[i].first > x){ //if cost of the book is higher then the total price, skip it
    //         dp[i] = bestSol;
    //         continue;
    //     }

    //     // if (book[i].second > bestSol.second){ //if discard all the previous book and just pick this one is a better solution, just pick this book
    //     //     dp[i] = {x - book[i].first, book[i].second};
    //     //     bestSol = dp[i];
    //     //     continue;
    //     // }

    //     for (int j = i - 1; j >= 0; j--){
    //         if (book[i].first <= dp[j].first){
    //             dp[i] = {dp[j].first - book[i].first, dp[j].second + book[i].second};
    //             if (dp[i].second > bestSol.second)
    //                 bestSol = dp[i];
    //             else if (dp[i].second == bestSol.second && dp[i].first > bestSol.second) //if same pages, bestSol is the one with max remain cost
    //                 bestSol = dp[i];
    //             else
    //                 dp[i] = bestSol;
    //         }
    //         dp[i] = bestSol;

    //     }
    // }
    
    // cout << bestSol.second;

    vector<vector<int>> dp(x + 1,vector<int>(n + 1));
    
    for(int i = 1; i < x + 1; i++)
        for (int j = 1; j < n + 1; j++)
            if (i - book[j].first < 0)//if current book is more expensive than the budget i
                dp[i][j] = dp[i][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - book[j].first][j - 1] + book[j].second);

    cout << dp[x][n];

    return 0;
}