#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long

int main() {
    ll t; cin >> t;
    vector<ll> ans;

    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll res = 0;
        for (ll i = l1; i <= r1; i++) {
            ll y = i;
            while (y <= r2) {
                if (y >= l2 && y <= r2) {
                    res++;
                }
                if (y > r2 / k) break;  // Prevent overflow
                y *= k;
            }
        }

        ans.push_back(res);
    }

    for (auto x : ans)
        cout << x << endl;

    return 0;
}
