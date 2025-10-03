#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    
    // for(int i = 0; i < n; i++)
    //     for (int j = i + 1; j < n; j++)
    //         for (int k = n - 1; k > j; k--)
    //             if (a[i] + a[j] > a[k]){
    //                 cout << "YES";
    //                 return 0;
    //             }
                
    
    for(int i = 0; i < n - 2; i++)
       if (a[i] + a[i + 1] > a[i + 2]){
        cout << "YES";
        return 0;
       }
        
    
    cout << "NO";

    return 0;
}