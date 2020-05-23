#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void multiply(ll M[2][2],ll A[2][2]){
	ll res[2][2];
	for(ll i=0;i<=1;i++){
		for(ll j=0;j<=1;j++){
			res[i][j] =  (( (M[i][0]%(MOD-1))*(A[0][j]%(MOD-1)))%(MOD-1) + ((M[i][1]%(MOD-1))*(A[1][j]%(MOD-1)))%(MOD-1))%(MOD-1);
		}
	}
	for(ll i=0;i<=1;i++){
		for(ll j=0;j<=1;j++){
			M[i][j] = res[i][j];
		}
	}
}
void power(ll M[2][2],ll n){
	if(n==0 || n==1) return;
	power(M,n/2);
	multiply(M,M);
	if(n%2==1){
		ll A[2][2] = {{1,1},{1,0}};
		multiply(M,A);
	}
}
ll fiboterm(ll n){
	if(n==0) return 0;
	//if(n==1) return 1; if this is used only base case in power is n==1
	ll M[2][2] = {{1,1},{1,0}};
	power(M,n-1);
	return M[0][0];
}
ll modexp(ll a,ll b,ll c){
	if(a==0) return 0;
	if(b==0) return 1;
	if(b%2==0){
		ll smallans = modexp(a,b/2,c);
		return (smallans*smallans)%c;
	}else{
		ll smallans = modexp(a,b-1,c);
		return (smallans*(a%c))%c;
	}
}
void solve(){
	ll a,b,n,ans;
	cin>>a>>b>>n;
	a++;b++;
	ll fibnminus1=fiboterm(n-1)%(MOD-1),fibn=fiboterm(n)%(MOD-1);
	ans = ((modexp(a,fibnminus1,MOD)%MOD) * (modexp(b,fibn,MOD)%MOD))%MOD;
	ans = (ans-1+MOD)%MOD;
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}













