#include<iostream>
#include<vector>
#include<map>
#include <algorithm> 


using namespace std;

int gcd(int a, int b)
{
   return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    int maxN = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];    
        maxN = max(maxN,a[i]);
    }
    int smallestN = a[0];

    for (int i = 1; i < n; i++){
        smallestN = gcd(smallestN,a[i]);
    }

    int sizeSet = maxN / smallestN;

    if ((sizeSet - a.size()) % 2 == 0)
        cout << "Bob";
    else 
        cout << "Alice";

    return 0;
}