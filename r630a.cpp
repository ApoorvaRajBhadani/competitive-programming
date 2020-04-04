#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll l,r,d,u;
	ll x0,y0,x1,y1,x2,y2;
	cin>>l>>r>>d>>u;
	cin>>x0>>y0>>x1>>y1>>x2>>y2;
	x1 = x1-x0;
	x2 = x2-x0;
	y1 = y1-y0;
	y2 = y2-y0;
	x0=0;
	y0=0;
	bool ans = true;
	if(abs(x1)>=1){
		ll t = min(l,r);
		l-=t;
		r-=t;
	}else if(abs(x2)>=1){
		ll t = min(l,r);
		l-=t;
		r-=t;
	}
	if(abs(y1)>=1){
		ll t = min(d,u);
		d-=t;
		u-=t;
	}else if(abs(y2)>=1){
		ll t = min(d,u);
		d-=t;
		u-=t;
	}
	if(l>abs(x1) ) ans = false;
	if(r>abs(x2)) ans = false;
	if(d>abs(y1)) ans = false;
	if(u>abs(y2)) ans = false;
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t,i;
	cin>>t;
	for(i=1;i<=t;i++){
		solve();
	}
	return 0;
}














