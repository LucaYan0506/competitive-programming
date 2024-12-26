#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

bool nextP (vector<int> &arr){
    int pivot = -1;
    for (int i = arr.size() - 2; i >= 0; i--){
        if (arr[i] < arr[i + 1]){
            pivot = i;
            break;
        }
    }   

    if (pivot == -1)
        return false;

    int nextN = -1;
    for (int i = arr.size() - 1; i >= 0; i--)
        if (arr[i] > arr[pivot]){
            swap(arr[i],arr[pivot]);
            reverse(arr.begin() + pivot + 1, arr.end());
            break;
        }


    return true;
}

string print(vector<int> arr){
    string s = "";
    for (int x : arr)
        s += to_string(x);

    return s;
}

int sP(vector<int> arr){
    int res = 0;
    for (int i = 0; i < arr.size(); i++){
        int mini = INT_MAX;
        for (int j = i; j < arr.size(); j++)
            mini = min(mini,arr[j]), res += mini;
    }

    return res;
}

void func(int n){
    vector<int> arr1 = {};
    for (int i = 0; i < n; i++)
        arr1.push_back(i+1);

    // cout << print(arr1) << " ";
    // cout << sP(arr1) << endl; 
    int count = 0;
    int a = sP(arr1);
    while(next_permutation(arr1.begin(),arr1.end())){
        // cout << print(arr1) << " ";
        // cout << sP(arr1) << endl; 
        count += sP(arr1) == a;
        // string s2 = print(arr2);
        // int a =0;
    }
    cout << count << endl;
}

int main(){
    for (int i = 4; i < 10; i++)
        func(i);
    return 0;
}