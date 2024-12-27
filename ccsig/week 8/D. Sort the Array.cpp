#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool isSorted(vector<int>& a){
    for (int i = 1; i < a.size(); i++)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    cin >> a[i];
    
    int start = -1;
    int end = -1;
    bool decreasing = false;

    for (int i = 1; i < n; i++){
        if (!decreasing && a[i] > a[i - 1])
            continue;

        if (!decreasing && a[i] < a[i - 1]){
            decreasing = true;
            start = i - 1;
            end = i;
        }
    
        if (decreasing && a[i] < a[i - 1]){
            end = i;    
        }
        
        if (decreasing && a[i] > a[i - 1]){
            decreasing = false;
        }
    }
    
    if (start != -1 && end != -1)
        sort(a.begin() + start, a.begin() + end + 1);
    
    if (isSorted(a)){
        if (start == end)
            cout << "yes" << endl << "1" << " " << "1";
        else
            cout << "yes" << endl << start + 1 << " " << end + 1;
    }
    else
        cout << "no";

    return 0;
}