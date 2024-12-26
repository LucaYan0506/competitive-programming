#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ifstream inputFile("input.txt");
        getline(inputFile, s, '\0');

        vector<int> suf(n + 1, 0);
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == '1') {
                suf[i] = suf[i + 1] + 1;
            } else {
                suf[i] = suf[i + 1] - 1;
            }
        }
 
        sort(suf.begin(), suf.end(),greater<int>());
 
        int cou = 0;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            cou += suf[i];
            ans++;
            if (cou >= k || suf[i] <= 0) {
                break;
            }
        }
 
        if (cou >= k) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
 
    return 0;
}