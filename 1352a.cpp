#include<bits/stdc++.h> 
using namespace std;
typedef int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,n,c=0;
	cin>>n;
	ll arr[n];
	fo(i,0,n-1) cin>>arr[i];
	fo(i,0,n-1){
		ll sum = arr[i];
		ll curr_sum=arr[0],start=0,j;
		fo(j,1,n){
			while(curr_sum>sum && start<j-1){
				curr_sum -= arr[start];
				start++;
			}
			if(curr_sum==sum && j-1-start>=1){
				c++;
				break;
			}
			if(j<n) curr_sum+=arr[j];
		}
	}
	cout<<c<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
