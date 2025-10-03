#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include <cmath>
 
using namespace std;
 
int main(){
    long long n; cin >> n;
    // set<long long> factors;
    long long res = 1;
    long long i = 2;

    
    for (long long i = 2; i * i <= n; i++){
        if (n % i == 0){
            res *= i;
            while(n % i == 0)
                n /= i;
        }
    }

    
    res *= n;
    cout << res;
    
    return 0;       
 }

// int longF(int n){
//     vector<int> divisors;
//     int res = n;
//     divisors.push_back(n);
//     for (int i = n / 2; i > 0; i--)
//         if (n % i == 0){
//             divisors.push_back(i);
//         }

//     for (int i = 0; i < divisors.size(); i++){
//         int valid = true;
//         for (int j = 2; j * j <= divisors[i]; j++){
//             if (divisors[i] % (j * j) == 0){
//                 valid = false;
//                 break;
//             }
//         }

//         if (valid){
//             return divisors[i];
//         }
//     }

//     return 1;
// }

// int main(){
//     for (int i = 1; i < 1e10; i++)
//         if (longF(i) != a(i))
//             cout << i << " " << longF(i) << a(i) << endl;



//     return 0;
// }