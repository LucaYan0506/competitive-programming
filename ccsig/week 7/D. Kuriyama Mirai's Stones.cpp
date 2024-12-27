#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> v(n + 1);
    vector<long long> u(n + 1);

    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        u[i + 1] = temp;
        v[i + 1] = temp;
    }
    
    sort(u.begin(),u.end());
    
    for (int i = 1; i <= n; i++){
        v[i] += v[i - 1];
        u[i] += u[i - 1];
    }

    int m; cin >> m;
    vector<long long> res(m);

    for (int i = 0; i < m; i++){
        int a,b,c; cin >> a; cin >> b; cin >> c;
        if (a == 1)
            res[i] = v[c] - v[b - 1];
        else
            res[i] = u[c] - u[b - 1];
    }

    for (int i = 0; i < m; i++)
        cout << res[i] << endl;


    return 0;
}