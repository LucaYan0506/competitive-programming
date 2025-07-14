/**
 * author: vanshgambhir
**/
#include<bits/stdc++.h>
#define ll long long
#define vi(n) vector<int> v(n);
#define loop(i, n) for (int i = 0; i < n; ++i)
#define all(v) v.begin(),v.end()
using namespace std;
void solve(){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(m);
		loop(i,m) cin>>v[i];
		sort(v.begin(),v.end());
		vector<ll> suff(m);
		suff[m-1]=v[m-1];
		ll tot=0;
		for(int i=m-2;i>=0;i--){
			suff[i]=v[i]+suff[i+1];
		}
		for(int i=0;i<m;i++){
			ll mini=v[i];
			ll maxiIdx=lower_bound(v.begin()+i+1,v.end(),n-mini)-v.begin();
			if(maxiIdx>=m) continue;
			ll maxi=suff[maxiIdx];
			ll cnt=m-maxiIdx;
			tot+=(((maxi+mini*cnt)-(n*cnt))+cnt);
		}
		cout<<tot*2<<endl;
	}
int main() {
	ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	 }
    return 0;
}