#include<iostream>
#include<string>
using namespace std;

string toUpper(string str){
    string res = "";
    for (char c : str){
        if (c >= 'a' && c <= 'z')
            res += (c + 'A' - 'a');
        else
            res += c;
    }

    return res;
}   

string customTolower(string str){
    string res = "";
    for (char c : str){
        if (c >= 'A' && c <= 'Z')
            res += (c + 'a' - 'A');
        else
            res += c;
    }

    return res;
}   

int main(){
    string s;cin >> s;
    int lowerC = 0;
    int upperC = 0;

    for (char c : s){
        if (c >= 'a' && c <= 'z')
            lowerC++;
        else
            upperC++;
    }

    if (lowerC < upperC)
        cout << toUpper(s);
    else   
        cout << customTolower(s);


    return 0;
}


