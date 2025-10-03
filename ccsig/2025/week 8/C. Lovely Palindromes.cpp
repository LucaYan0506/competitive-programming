#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    string str; cin >> str;
    int n = str.size();
    for (int i = 0; i < n; i++)
        cout << str[i];
    for (int i = n - 1; i >= 0; i--)
        cout << str[i];


    return 0;
}