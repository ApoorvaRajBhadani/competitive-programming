#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,k,i,j;
	string s,ans="";
	cin>>n>>k;
	cin>>s;
	sort(s.begin(),s.end());
	if(s[0]!=s[k-1]){
		//case1
		cout<<s[k-1]<<endl;
	}else{
		ans=s[0];
		string sleft = s.substr(k,n-k);
		bool allsame = true;
		for(i=1;i<n-k;i++){
			if(sleft[i]!=sleft[i-1]) allsame=false;
		}
		if(allsame){
			for(i=0;i<(n-k)/k;i++) ans+=s[n-1];
			if((n-k)%k>0) ans+=s[n-1];
		}else{
			ans+=sleft;
		}
		cout<<ans<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
