#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long n,x; cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int smallAIndex = 0;

    for (int i = 1; i < n; i++)
        if (a[smallAIndex] > a[i])
            smallAIndex = i;

    long long balls = n * a[smallAIndex];

    return 0;
}