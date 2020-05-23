#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll t,p,ans=1,k,i;
	cin>>t>>p;
	k=t/p;
	if(k%2==1) ans*=p-1;
	for(i=1;i<=(t%p);i++){
		ans = (ans*(i%p))%p;
	}
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
