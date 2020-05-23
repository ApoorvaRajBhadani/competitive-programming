#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,j;
	cin>>n;
	ll dp[n+1],arr[n+1];
	for(i=1;i<=n;i++) cin>>arr[i];
	dp[1]=1;
	for(i=2;i<=n;i++){
		dp[i]=0;
		//cout<<num<<endl;
		for(j=1;j*j<=i;j++){
			if(i%j==0){
				//cout<<j<<" "<<num/j;
				if(arr[j]<arr[i]){
					ll posans = dp[j]+1;
					if(posans>=dp[i]){
						dp[i]=posans;
					}
				}
				if(arr[i/j]<arr[i]){
					ll posans = dp[i/j]+1;
					if(posans>=dp[i]){
						dp[i]=posans;
					}
				}
				
			}
		}
		//cout<<endl;
	}
	ll ans=1;
	for(i=1;i<=n;i++) {
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
