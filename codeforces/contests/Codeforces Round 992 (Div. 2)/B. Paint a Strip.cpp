#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;cin >> t;
    vector<int> res;
    while (t--)
    {
        int n;cin >> n;
        int count = 1;
        int temp = 1;
        
        while(temp < n){
            count++;
            temp = (temp + 1) * 2;
        }
        
        res.push_back(count);

    }

    for (auto x : res)
        cout << x << endl;

    return 0;
}