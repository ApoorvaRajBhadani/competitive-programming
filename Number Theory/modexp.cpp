#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int modexp(ll a,ll b,ll c){
	if(a==0) return 0;
	if(b==0) return 1;
	if(b%2){
		long smallans = modexp(a,b-1,c);
		long ans = a%c;
		ans = (ans*smallans)%c;
		return (int)ans;
	}else{
		long smallans = modexp(a,b/2,c);
		long ans = (smallans*smallans)%c;
		return (int)ans;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll a,b,c;
	cin>>a>>b>>c;
	cout<<modexp(a,b,c)<<endl;
	return 0;
}
