#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;


void fast_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const ll inf = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i].pop_back();
    }
    map<long double, string> mp;
    string name = "";
    for (string x : s)
    {
        long double unit = 0;
        int j = 0;
        while (j < x.size() && x[j] != '.')
        {
            unit = unit * 10 + (x[j] - '0');
            j++;
        }

        long double decimal = 0;
        j++;
        long double temp = 10;
        while (j < x.size())
        {
            decimal += (long double)(x[j] - '0') / temp;
            temp *= 10;
            j++;
        }

        decimal += unit;
        if (mp.count(decimal)){
            cout << mp[decimal] << endl;
        }else{
            name += 'x';
            mp[decimal] = name;
            cout << mp[decimal] << endl;
        }
    }


}

int main()
{
    fast_io();
    int t;
    // cin>>t;
    // while(t--)
    solve();
}