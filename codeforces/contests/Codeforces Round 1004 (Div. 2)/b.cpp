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

static bool cmp(int&a, int &b){
    return a > b;
}

vector<int> a;//store freq
vector<bool> bag2;

bool need(int curr){
    if (curr < 0)
        return false;


    //make sure that curr is in bag2
    if (!bag2[curr]){
        if (a[curr] >= 2){
            bag2[curr] = true;
            a[curr] -= 2;
        }else if (a[curr] == 1){
            a[curr]--;
            if (need(curr - 1))
                bag2[curr] = true;
            else    
                return false; //if it's not psosible to have curr in bag2, but i need curr, return false
            
        }else if (need(curr - 1) && need(curr - 1))//2 curr-1 needed
            bag2[curr] = true;
        else    
            return false; //if it's not psosible to have curr in bag2, but i need curr, return false
    }

    if (a[curr] > 0){
        a[curr]--;
        return true;
    }

    if (a[curr] == 0){
        if (need(curr - 1)){
            return true;
        }else  
            return false;
    }
    return false;
}

void solve(){
    int n; cin >> n;
    //reset glob var
    a = vector<int>(n + 1);
    bag2 = vector<bool>(n + 1);
    FOR(i,0,n){
        int temp; cin >> temp;
        a[temp]++;

    }

    FORI(i,n, 0){
        a[i] = a[i] % 2;

        if (a[i] == 0)
            continue;;

        if (need(i - 1))
            a[i]--;//a[i] == 1, so (i - 1) is needed 
        else{
            cout << "NO" << endl;
            return;
        }
    }

    for (auto x : a)
        if (x > 0){
            cout << "NO" << endl;
            return;
        }

    cout << "YES" << endl;
}

int32_t main(){
    fastIO();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}