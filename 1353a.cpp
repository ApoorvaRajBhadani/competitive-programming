#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,n,m;
	cin>>n>>m;
	if(n==1) {cout<<0<<endl;
	return;}
	if(n==2) {cout<<m<<endl;
	return;}
	if(n%2==1){
		ll terms = (n-1)/2;
		ll val = m/terms;
		ll sum = (val+(m%terms))*2 + val*2*(terms-1);
		cout<<sum<<endl;
	}else{
		ll terms = (n)/2;
		ll val = m/terms;
		ll sum = (val+(m%terms))*2 + val*2*(terms-2) + val*2;
		cout<<sum<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}
