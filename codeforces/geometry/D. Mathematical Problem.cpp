#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define oo 1000000000000000000ll

const int mod = 1e9+7;
using namespace std;

random_device dev;
mt19937 rng(dev());
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

vector<int> SieveOfEratosthenes(int n){
    vector<bool> isPrime(n + 1, true);
    for (int p = 2; p * p <= n; p++) 
        if (isPrime[p] == true) 
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;

    vector<int> primes;
    FOR(i,2, n + 1)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

void fastIO(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
}

// void solve(){
//     int i = 1;
//     while(true){
//         i+=2;
//         map<string,int> res;
//         FOR(j,1,pow(10,i / 2 + 1)){
//             string temp = to_string(j*j);
//             sort(all(temp));
//             if (temp.size() == i)
//                 res[temp]++;
//             if (temp.size() > i)
//             break;
            
//         }
//         int highest = 0;
//         for (auto [key,val] : res){
//             highest = max(highest, val);
//             if (val == 99){
//                 cout << key; //11
//                 return;
//             }
//         }
//         cout << i << " " << highest << endl;

//     }

// }

void solve(vector<string> preCompute){
    int n; cin >> n;
    if (n < 11){
        map<string,vector<string>> res;
        FOR(j,1,pow(10,n / 2 + 1)){
            string key = to_string(j*j);
            string val = to_string(j*j);
            sort(all(key));
            if (key.size() == n)
                res[key].push_back(val);
            if (key.size() > n)
            break;
            
        }
        int highest = 0;
        string highest_key = "";
        for (auto [key,val] : res)
            if (highest < val.size()){
                highest = val.size();
                highest_key = key;
            }    
        for (int i = 0; i < n; i++)
            cout << res[highest_key][i] << endl;

        return;
    }

    string extra = "";
    FOR(i,0,n - 11)
        extra += '0';
    for (int i = 0; i < n; i++)
        cout << preCompute[i] + extra << endl;
}

int32_t main(){
    fastIO();

    int i = 11;

    map<string,vector<string>> res;
    vector<string> preCompute;
    FOR(j,1,pow(10,i / 2 + 1)){
        string key = to_string(j*j);
        string val = to_string(j*j);
        sort(all(key));
        if (key.size() == i)
            res[key].push_back(val);
        if (key.size() > i)
        break;
        
    }
    int highest = 0;
    string highest_key = "";
    for (auto [key,val] : res)
        if (highest < val.size()){
            highest = val.size();
            highest_key = key;
        }    
    for (int i = 0; i < 99; i++)
        preCompute.push_back(res[highest_key][i]);


    int t; cin >> t;
    while(t--)
        solve(preCompute);

    return 0;
}