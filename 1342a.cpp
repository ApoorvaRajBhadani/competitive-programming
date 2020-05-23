#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll a,b,q,lcm,mn;
	cin>>a>>b>>q;
	lcm = (a*b)/__gcd(a,b);
	mn = max(a,b);
	//ll c=0;
	//for(ll i=0;i<=99;i++){
		//cout<<i<<" "<<(i%a)%b<<" "<<(i%b)%a<<endl;
		//if((i%a)%b != (i%b)%a) c++;
	//}
	//cout<<c<<endl;
	while(q--){
		ll l,r,ans2,ans1;
		cin>>l>>r;
		l--;
		ans2 = (lcm-mn)*(r/lcm);
		ll rem2 = (r%lcm) + 1;
		if(rem2>=mn) ans2+=rem2-mn;
		ans1 = (lcm-mn)*(l/lcm);
		ll rem1 = (l%lcm) + 1;
		if(rem1>=mn) ans1+=rem1-mn;
		//cout<<ans2<<" ";
		cout<<ans2-ans1<<" ";
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
