#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll getN(double n,double k){
	ll ans=sqrt(8*k-7);
	ans+=1;
	ans/=2;
	ll newans = (ll)ans;
	return newans;
}
void solve(){
	double n,k,N;
	cin>>n>>k;
	N = getN(n,k);
	ll f,s;
	f = n-N-1;
	s = n - (k - ( N*N/2 - N/2 + 1) + 1);
	//cout<<f<<' '<<s<<endl;
	for(ll i=0;i<n;i++){
		if(i==f || i==s) cout<<'b';
		else cout<<'a';
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
