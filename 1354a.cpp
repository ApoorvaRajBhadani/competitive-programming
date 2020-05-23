#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b<a){
		ll net = c-d;
		if(net<=0){
			cout<<-1<<endl;
		}else{
			ll extra = ceil((double)(a-b)/net);
			cout<<b+c*extra<<endl;
		}
	}else{
		cout<<b<<endl;
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
