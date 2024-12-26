#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin >> n;
    int res = 0;
    int man = 0;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        if (temp == -1){
            if (man == 0)
                res++;
            else
                man--;
        }else
            man += temp;
    }

    cout << res;


    return 0;
}