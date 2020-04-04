#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll dp[101][2];
ll k,d;
ll helper(ll sumleft,bool isddone){
	if(sumleft==0&&isddone) return 1;
	if(sumleft<0) return 0;
	if(dp[sumleft][isddone]>-1)return dp[sumleft][isddone];
	ll i,c=0;
	for(i=1;i<=k;i++){
		ll sum = helper(sumleft-i,(isddone||i>=d)?true:false);
		c = (c + sum%MOD)%MOD;
	}
	return dp[sumleft][isddone]=c;
}
int main(){
	ll n;
	cin>>n>>k>>d;
	memset(dp,-1,sizeof dp);
	cout<<helper(n,false);
	return 0;
}
