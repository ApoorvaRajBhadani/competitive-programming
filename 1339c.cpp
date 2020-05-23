#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++) cin>>arr[i];
	ll max_so = arr[0],ans = 0;
	for(i=0;i<n;i++){
			max_so=max(max_so,arr[i]);
			ll j=0,sum=pow(2,j+1)-j-2,req = max_so - arr[i];
			while(req>sum){
				j++;
				sum=pow(2,j+1)-j-2;
				//cout<<sum<<endl;
			}
			ans = max(ans,j);
			cout<<j<<" ";
			for(j=j-1;j>=1;j--){
				if((req-sum)>=pow(2,j)-1){
					sum-=pow(2,j)-1;
				}
			}
			max_so=max(max_so,arr[i]+sum);
	}
	cout<<endl<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
