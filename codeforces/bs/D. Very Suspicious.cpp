#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include <fstream>

using namespace std;

// int main(){
//     int y = 2;
//     int i = 3;
//     ofstream myfile;
//     myfile.open ("example.txt");

//     myfile << y << ",";
//     while(i <= 38729){
//         int x = i;
//         int temp = (x/3) * 4;
//         if (x % 3 == 2)
//             temp += 2;
//         y+= temp;
//         myfile << y << ",";
//         // cout << y << ",";
//         i++;
//     }
//      myfile.close();

//     // cout << i - 2;

//     //38729

//     return 0;
// }

int calcFx(int x){
    x++;
    int k = x / 3;
    return 4*(3*k*(k-1)/2 + k*(x%3)) + 2*(x/3);
}

int main(){
    // vector<int> fx = {0,0,2};
    // int y = 2;
    // int i = 3;
    // while(i <= 38731){
    //     int x = i;
    //     int temp = (x/3) * 4;
    //     if (x % 3 == 2)
    //         temp += 2;
    //     y+= temp;
    //     fx.push_back(y);
    //     i++;
    // }
    int t; cin >> t;
    vector<int> res;
    while (t--){
        int n; cin >> n;

        int left = 0, right = 38731;
        while(left <= right){
            int mid = (left + right) / 2;
            auto val = calcFx(mid);
            if (val < n){
                left = mid + 1;
            }else if (val > n)
                right = mid - 1;
            else{
                right = mid;
                break;
            }
        }
            if (calcFx(right) >= n)
                res.push_back(right);
            else
                res.push_back(right + 1);
    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}
