#include<bits/stdc++.h>

#define int long long 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORI(i, a, b) for (int i = (a); i > (b); i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()

const int mod = 1e9+7;
using namespace std;

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

void solve(){
    vector<int> freqS(26);
    vector<int> freqT(26);
    string s,t; cin >> s >> t;
    for (char c : s)
        freqS[c - 'a']++;
    for (char c : t)
        freqT[c - 'a']++;
    
    bool automaton = s.size() != t.size();
    bool array = false;

    FOR(i,0,26){
        if (freqT[i] > freqS[i]){
            cout << "need tree" << endl;
            return;
        }
    }

    int i = 0, j = 0;
    while(i < s.size() && j < t.size()){
        if (t[j] == s[i])
            i++, j++;
        else
            i++;
    }

    if (j != t.size())
        array = true;

    if (array && automaton)
        cout << "both" << endl;
    else if (array)
        cout << "array" << endl;
    else if (automaton)
        cout << "automaton" << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}