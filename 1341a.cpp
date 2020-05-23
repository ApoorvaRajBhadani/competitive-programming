#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,a,b,c,d,i,j;
	cin>>n>>a>>b>>c>>d;
	ll maxtotalwt = c+d;
	ll mintotalwt = c-d;
	ll mxwt = (a+b)*n;
	ll mnwt = (a-b)*n;
	//cout<<maxtotalwt<<mintotalwt<<mxwt<<mnwt<<endl;
	if(mnwt<=maxtotalwt && mnwt>= mintotalwt){
		cout<<"YES"<<endl;
	}else if(mxwt>=mintotalwt && mxwt<=maxtotalwt){
		cout<<"YES"<<endl;
	}else if(mnwt<=mintotalwt && mxwt>=maxtotalwt){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
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
