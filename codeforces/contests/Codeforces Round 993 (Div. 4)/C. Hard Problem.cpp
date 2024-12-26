#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t; cin >> t;
    vector<int> res;
    while ((t--))
    {
        int m,a,b,c; cin >> m >> a >> b >> c;

        int m1 = m, m2 = m;
        m1 -= a;
        m2 -= b;

        int ans = 0;
        if (m1 <= 0)
            ans += m;
        else{
            if (c < m1)
                m1 -= c, c = 0;
            else{
                c -= m1;
                m1 = 0;
            }
            ans += (m - m1);
        }

        if (m2 <= 0)
            ans += m;
        else{
            if (c < m2)
                m2 -= c, c = 0;
            else{
                c -= m2;
                m2 = 0;
            }
            ans += (m - m2);
        }

        res.push_back(ans);
    }
    
    for (auto x : res)
        cout << x << endl;

    return 0;
}