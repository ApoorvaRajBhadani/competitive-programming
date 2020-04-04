#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 998244353 
int fact(int n) 
{ 
    if (n <= 1) 
        return 1; 
    return n*fact(n-1); 
} 
  
ll nPr(ll n, ll r) 
{ 
	ll ans=1,i;
	for(i=n;i>(n-r);i--){
		ans = ((ans%MOD) * (i%MOD))%MOD;
	}
	return ans;
    return fact(n)/fact(n-r); 
} 
int main(){
	ll n,m,i,c=0,j;
	cin>>n>>m;
	for(i=1;i<=(n-2);i++){
		for(j=max(i+1,n-n-i);j<=m;j++){
			ll t=0;
			t = nPr(j-1,i)%MOD;
			t = (t*(i%MOD))%MOD;
			t = (t*((n-i-1)%MOD))%MOD;
			t = (t*(nPr(j-1-i,n-i-2)%MOD))%MOD;
			//t = nPr(j-1,i) * i*(n-i-1) * nPr(j-1-i,n-i-2);
			c=((c%MOD)+(t%MOD))%MOD;
		}
	}
	cout<<c;
	
return 0;
}
