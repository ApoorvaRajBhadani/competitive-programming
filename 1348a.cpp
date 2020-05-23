#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,diff=0,val=2,i;
	cin>>n;
	for(i=1;i<=(n/2)-1;i++){
		diff+=val;
		val*=2;
	}
	for(;i<=n-1;i++){
		diff-=val;
		val*=2;
	}
	diff+=val;
	cout<<diff<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
