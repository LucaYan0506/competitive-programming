#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define int long long
#define double long double
typedef long long ll;
const int M_PI = acos(-1);
 
void fast_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const ll oo = 1e9;
vector<double> a;
double r = 1000;

double degreeToRadiant(double x){
    return x * M_PI / (double)180 ;
}

double calcArea(int i, int j){
    double angleDiff = abs(a[i] - a[j]);
    // angleDiff = degreeToRadiant(angleDiff);

    double circleArea = M_PI * angleDiff * r * r / (double)(360) ;

    double alpha = (double)(180 - angleDiff) / (double)2;
    alpha = degreeToRadiant(alpha);

    double base = abs(cos(alpha)) * r, h = abs(sin(alpha)) *r;
    double triangleArea = base * h ;
    angleDiff = degreeToRadiant(angleDiff);
    double temp = sin(angleDiff);
    double area = 0.5 * r*r * (angleDiff - sin(angleDiff));
    return area;
}

void solve()
{
    int n, p; cin >> n >> p;
    a = vector<double>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<double> totArea(n,0);
    for (int i = 1; i < n; i++)
        totArea[i] = totArea[i - 1] + calcArea(i,i - 1);

                // area, index of first point picked
    vector<vector<pair<double,int>>> dp(n, vector<pair<double,int>>(n + 1, {oo,-1}));
    for (int i = 0; i < n; i++)
        if (i + 1 <= p)
            dp[i][i + 1] = {totArea[i], 0};

    for (int i = 0; i < n; i++)
        dp[i][1] = {0, i};

    for (int i = 0; i < n; i++){
        for (int k = 2; k <= i + 1; k++){

            for (int j = k - 2; j < i; j++){
                if (k == p){
                    if (dp[j][k-1].first + calcArea(i,j) + calcArea(dp[j][k-1].second,i) < dp[i][k].first)
                        dp[i][k] = {dp[j][k-1].first + calcArea(i,j) + calcArea(dp[j][k-1].second,i), dp[j][k-1].second};
                }
                else if (k < p){
                    if (dp[j][k-1].first + calcArea(i,j) < dp[i][k].first)
                        dp[i][k] = {dp[j][k-1].first + calcArea(i,j), dp[j][k-1].second};
                }
                int e = calcArea(i,j);
                int b = calcArea(i,0);
                if (i == 3)
                int c = 0;
            }

            
            
        }
    }

    double res = M_PI * r * r;
    double minDP = oo;
    for (int i = 0; i < n; i++){
        minDP = min(minDP, dp[i][p].first);

    }
    cout << res - minDP << endl;
}

int32_t main()
{
    fast_io();
    int t;
    // cin>>t;
    // while(t--)
    solve();

    return 0;
}