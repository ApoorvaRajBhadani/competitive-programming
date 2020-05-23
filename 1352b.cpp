#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,a,b,c;
	cin>>a>>b>>c;
	string ans= "";
	if(c>0)fo(i,1,c+1) ans+='1';
	if(a>0) fo(i,1,a+1) ans+='0';
	
	if(a>0 && c>0) b--;
	if(ans.size()==0) ans+='0';
	char curr = ans[ans.size()-1];
	if(curr=='0') curr='1';
	else curr='0';
	fo(i,1,b){
		ans+=curr;
		if(curr=='0') curr='1';
		else curr='0';
	}
	cout<<ans<<endl;
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
