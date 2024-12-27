#include<iostream>
#include<vector>

using namespace std;

string recipe;
vector<int> n(3);
vector<int> p(3);
long long r;
vector<int> freq(3,0); //freq[0] = b freq[1] = s freq[2] = c

bool canMakeH(long long nH){
    long long newR = r;
    for (int i = 0; i < 3; i++)
        if (freq[i] * nH > n[i])
            newR -= ((freq[i] * nH - n[i]) * p[i]);
    

    return newR >= 0;
}

int main(){
    cin >> recipe;
    for (int i = 0; i < 3; i++)
        cin >> n[i];
    for (int i = 0; i < 3; i++)
        cin >> p[i];

    cin >> r;

    long long res = 0;

    for (char c : recipe){
        freq[0] += (c == 'B');
        freq[1] += (c == 'S');
        freq[2] += (c == 'C');
    }

    long long left = 0, right = 1e13;
    while(left <= right){
        long long mid = (right + left) / 2;
        if (canMakeH(mid))
            res = mid, left = mid + 1;
        else 
            right = mid - 1;
    }
    cout << res;

    return 0;
}
