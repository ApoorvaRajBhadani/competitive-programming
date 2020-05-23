#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,a,mx=0;
	cin>>n;
	map<ll,ll> mp;
	for(i=0;i<n;i++){
		cin>>a;
		mp[a]++;
		mx=max(mx,mp[a]);
	}
	ll sz=mp.size();
	ll ans= max(  min(mx,sz-1)  ,  min(mx-1,sz));
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
