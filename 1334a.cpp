#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n;
	cin>>n;
	ll p,c,pp=INT_MIN,cp=INT_MIN;
	bool ans = true;
	for(ll i=0;i<n;i++){
		cin>>p>>c;
		if(!(c>=cp && p>=pp && p>=c)){
			//cout<<"NO\n";
			ans = false;
			//return;
		}
		if(   !(c-cp <= p-pp)){
			ans = false;
		}
		pp = p;
		cp = c;
	}
	if(ans == false) {cout<<"NO\n";return;}
	cout<<"YES\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
