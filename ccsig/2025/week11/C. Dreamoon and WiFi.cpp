#include<iostream>
#include<vector>

using namespace std;

int main(){
    string s1; cin >> s1;
    string s2; cin >> s2;

    int goalPos = 0;
    for (char x : s1)
        if (x == '+')
            goalPos++;
        else
            goalPos--;
        
    vector<int> arr;
    arr.push_back(0);
    for (int i = 0; i < s2.size(); i++)
        if (s2[i] == '+')
            for (int j = 0; j < arr.size(); j++)
                arr[j]++;
        else if (s2[i] == '-')
            for (int j = 0; j < arr.size(); j++)
                arr[j]--;
        else{
            vector<int> newArr;
            for (int j = 0; j < arr.size(); j++){
                newArr.push_back(arr[j] + 1);
                newArr.push_back(arr[j] - 1);
            }
            arr = newArr;
        }

    double nCorrectPos = 0;
    for (int pos : arr)
        nCorrectPos += pos == goalPos;

    cout.precision(10);
    cout << nCorrectPos / arr.size();
}