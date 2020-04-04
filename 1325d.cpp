#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
#define tezz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
	tezz
	ll u,v;
	cin>>u>>v;
	if(u>v || (v-u)%2==1){
		cout<<-1;
		return 0;
	}
	ll ans = (v-u)/2;
	if(u==0){
		if(v==0){
			cout<<0;
			return 0;
		}
		cout<<2<<endl<<ans<<" "<<ans;
		return 0;
	}
	if(ans ==0){
		cout<<1<<endl<<u;
		return 0;
	}
	if((u^ans)==(u+ans)){
		cout<<2<<endl<<ans+u<<" "<<ans;
		return 0;
	}
	cout<<3<<endl<<u<<" "<<ans<<" "<<ans;
	return 0;
}
