#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    long n;
    cin >> n;
    vector<pair<long long, long long>> polong(n);
    map<long long, long long> freqx;
    map<long long, long long> freqy;
    map<pair<long long, long long>, long long> freqp;

    // Populate frequency maps
    for (long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        freqx[x]++;
        freqy[y]++;
        freqp[{x, y}]++;
        polong[i] = {x, y};
    }

    long long res = 0;

    for (const auto &entry : freqx) {
        long long count = entry.second;
        res += (count * (count - 1)) / 2; // Pairs with the same x
    }
    for (const auto &entry : freqy) {
        long long count = entry.second;
        res += (count * (count - 1)) / 2; // Pairs with the same y
    }
    for (const auto &entry : freqp) {
        long long count = entry.second;
        res -= (count * (count - 1)) / 2; // Remove over-counted duplicate pairs
    }

    cout << res << endl;
    return 0;
}
