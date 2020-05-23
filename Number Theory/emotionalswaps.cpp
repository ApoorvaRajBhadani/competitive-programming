#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll fact[1000001];
void precompute(){
	fact[0]=1;
	for(ll i=1;i<=1000000;i++){
		fact[i] = (fact[i-1]*(i%MOD))%MOD;
	}
}
ll modexp(ll a,ll b,ll c){
	if(a==0) return 0;
	if(b==0) return 1;
	if(b%2==0) {
		ll sa = modexp(a,b/2,c);
		return (sa*sa)%c;
	}else{
		ll sa = modexp(a,b-1,c);
		return ((a%c)*sa)%c;
	}
}
ll modinv(ll a,ll m){
	return modexp(a,m-2,m);
}
ll ncrmodpfermat(ll n,ll r,ll p){
	if(r==0) return 1;
	ll ans = fact[n]%p;
	ans = (ans*modinv(fact[r],p))%p;
	ans = (ans*modinv(fact[n-r],p))%p;
	return ans;
}
void solve(){
	ll n,k,i,j,ans;
	cin>>n>>k;
	ans = modexp(2,k,MOD);
	ans = (ans*ncrmodpfermat(n,k,MOD))%MOD;
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	precompute();
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
