#include<bits/stdc++.h>

#define int unsigned long long 
#define double long double 
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
int get_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
// uniform_int_distribution<std::mt19937::result_type> uni(1,6); // distribution in range [1, 6]
// cout << uni(rng) << endl;

struct Point{
    int x,y;
    Point(){
        x = -1;
        y = -1;
    }
    Point(int first, int second){
        x = first;
        y = second;
    }

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};

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
// bitmask failed
void solve2(){
    int n; cin >> n;
    string s = to_string(n);
    int len = s.size();
    vector<int> power10(20);
    power10[0] = 1;
    FOR(i,1,20)
        power10[i] = power10[i - 1] * 10;

    vector<int> res;
    int mask = 1 << len;
    while(mask--){
        if (mask == 511)
            int b = 0;
        int temp = 1 << (len-1), mask_copy = mask;
        int possibleRes = 0; 
        int i = 0;
        while(mask_copy){
            if (mask_copy & temp){
                possibleRes += (s[i] - '0') * power10[len-i-1];
                mask_copy -= temp;
            }
            i++;
            temp = temp >> 1;
        }
        int possibleResSize = to_string(possibleRes).size();
        if (len - possibleRes == 0)
            continue;
        int a = possibleRes;
        possibleRes = possibleRes + possibleRes * power10[len - possibleResSize];
        if (possibleRes == n)
            res.push_back(a);
    }

    sort(all(res));
    res.erase( unique( all(res)), res.end() );
    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i] << endl;
}


void solve(){
    int n; cin >> n;
    vector<int> power10(20);
    power10[0] = 1;
    FOR(i,1,20)
        power10[i] = power10[i - 1] * 10;

    vector<int> res;
    FOR(i,1,18){
        int den = 1 + power10[i];
        if (den > n)
            break;

        if (n % den == 0)
            res.push_back(n/den);
    }

    sort(all(res));
    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i] << endl;

}
int32_t main(){
    fastIO();
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}