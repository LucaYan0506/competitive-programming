#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<char> res(n);

    int i,j;

    if (n % 2 == 1){
        i = n / 2;
        j = i - 1;
        bool check = true;
        for (char c : s){
            if (check)
                res[i++] = c;
            else
                res[j--] = c;

            check = !check;
        } 
    }
    else{
        i = n / 2 - 1;
        j = i + 1;
        bool check = true;
        for (char c : s){
            if (check)
                res[i--] = c;
            else
                res[j++] = c;

            check = !check;
        } 
    } 



    
    for (char c : res)
        cout << c;


    return 0;
}