#include<bits/stdc++.h>

#define int unsigned long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int mod = 1e9+7;
using namespace std;

void fastIO(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
}

int customPow(int base, int exp){
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) 
            res = (res * base) % mod;
        base = (base * base) % mod; 
        exp /= 2;     
    }

    return res;
}

int32_t main(){
    fastIO();
    vector<int> right(1e5);
    right[0] = 0;
    for (int n = 1; n < 1e5; n++)
        right[n] = (right[n - 1] + n * customPow(10,n - 1)) % mod;
    
    string str; cin >> str;
    int count = 0;
    for (int i = 0; i < str.size(); i++){
        int x = str[i] - '0';
        int n = str.size() - i - 1;
        int left = (((i * (i + 1)) / 2) * customPow(10,n)) % mod;
        int temp = (right[n] + left) % mod;
        count = (count + x * temp) % mod;
    }

    cout << count;

    return 0;
}


/*
10000000000000000 * 10000000000000000
*/