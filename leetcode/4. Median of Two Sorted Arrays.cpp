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

int kthMin(vector<int>& nums1, vector<int>& nums2, int k){
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;

    // empty case
    if (i >= n)
        return nums2[j + k - 1];
    else if (j >= m)
        return nums1[i + k - 1];

    while(k > 1){
        int newK = k / 2 - 1;
        newK = min({n - i - 1, m - j - 1, newK});
        i += newK;
        j += newK;

        if (nums1[i] < nums2[j])
            j -= newK,
            i++;
        else
            i -= newK,
            j++;

        k -= (newK + 1);
        if (i >= n)
            return nums2[j + k - 1];
        else if (j >= m)
            return nums1[i + k - 1];
    }

    return min(nums1[i], nums2[j]);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    double res = 0;

    if ((n + m) % 2 == 0)
        res = (kthMin(nums1, nums2, (n + m) / 2) + kthMin(nums1, nums2, (n + m) / 2 + 1)) / 2.0;
    else
        res = kthMin(nums1, nums2, (n + m) / 2 + 1);

    return res;
}


void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n); 
    vector<int> b(m);
    FOR(i,0,n)
        cin >> a[i];
    FOR(i,0,m)
        cin >> b[i];
        
    cout << findMedianSortedArrays(a,b) << endl;
}

int32_t main(){
    fastIO();
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}