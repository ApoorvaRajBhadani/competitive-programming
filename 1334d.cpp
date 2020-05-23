#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i;
	cin>>n;
	ll a[n],b[n];
	for(i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	ll sum=0,mn=LLONG_MAX;
	ll m[n],ms[n];
	for(i=0;i<n;i++){
		m[i] =  a[i]-b[(i-1+n)%n] > 0 ?a[i]-b[(i-1+n)%n]:0;
		sum+=m[i];
		ms[i]=sum;
	}
	ll ans[n];
	for(i=0;i<n;i++){
		ans[i] = a[i] + ms[n-1] - ms[i];
		if(i>0) ans[i]+=ms[i-1];
		mn = min(mn,ans[i]);
	}
	fo(i,0,n-1)cout<<ans[i]<<" ";
	cout<<endl;
	cout<<mn<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}









