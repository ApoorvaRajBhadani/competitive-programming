#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll F(ll x,ll y,ll k){
	return ((x&k)*(y&k));
}
void solve(){
	ll x,y,z=LLONG_MAX,l,r,i,ans=LLONG_MIN;
	cin>>x>>y>>l>>r;
	for(i=l;i<=r;i++){
		ll myans = F(x,y,i);
		if(myans>ans){
			z = i;
			ans = myans;
		}
	}
	//cout<<"-----------------"<<endl;
	//cout<<"x is "<<x<<endl;
	//cout<<"y is "<<y<<endl;
	//cout<<"z chosen is "<<z<<" in "<<l<<" to "<<r<<endl;
	//cout<<"Fmax is "<<ans<<endl;
	cout<<z<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
