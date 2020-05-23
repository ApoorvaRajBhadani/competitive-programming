#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll power(ll x,ll n){
	if(x==0) return 0;
	if(n==0) return 1;
	ll val = power(x,n/2);
	if(n%2==0){
		return val*val;
	}else return x*val*val;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll x,n;
	cin>>x>>n;
	cout<<power(x,n)<<endl;
	return 0;
}
