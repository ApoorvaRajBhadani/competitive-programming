#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll phi[1000001];
void sieve(){
	ll i,j;
	for(i=0;i<=1000000;i++) phi[i]=i;
	for(i=2;i<=1000000;i++){
		if(phi[i]==i){
			for(j=i;j<=1000000;j+=i){
				phi[j]/=i;
				phi[j]*=(i-1);
			}
		}
	}
}
ll result[1000001];
void solveall(){
	ll i,j,ans=0;
	memset(result,0,sizeof(result));
	for(i=1;i<=1000000;i++){
		for(j=2;i*j<=1000000;j++){
			result[i*j]+=i*phi[j];
		}
	}
	for(i=1;i<=1000000;i++) result[i]+=result[i-1];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	sieve();
	solveall();
	while(true){
		ll n;
		cin>>n;
		if(n==0) break;
		cout<<result[n]<<endl;
	}
	return 0;
}
