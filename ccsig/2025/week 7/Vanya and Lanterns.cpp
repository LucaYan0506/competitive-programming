#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    double d = 0;
    int n; cin >> n;
    int l; cin >> l;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(),a.end());
    if (a[0] != 0)
        d = a[0];

    for (int i = 1; i < n; i++)
        d = max(d,(a[i] - a[i - 1]) / 2.00000000000000);
    
    if (a[n - 1] != n)
        d = max(d,double(l - a[ n - 1]));


    cout.precision(12);
    cout << fixed << d;
    return 0;
}

/*
0 3 5 7 9 14 15
        5
*/