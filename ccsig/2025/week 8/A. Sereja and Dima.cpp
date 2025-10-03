#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];


    int a = 0, b = 0;
    int i = 0,j = l.size() - 1;
    bool isA = true;
    while(i <= j){
        if (isA){
            if (l[i] < l[j])
                a+= l[j--];
            else
                a += l[i++];

        }else{
            if (l[i] < l[j])
                b += l[j--];
            else
                b += l[i++];
        }

        isA = !isA;
    }
    

    cout << a << " " << b;




    return 0;
}