#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,d,i,mn=LLONG_MAX;
	cin>>n>>d;
	ll arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	 
	for(i=n-1;i>=0;i--){
		ll lastday = (d/arr[i]) * arr[i];
		d = min(d,lastday);
	}
	cout<<d<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
