#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,k,i,j;
	cin>>n>>k;
	ll arr[n+1];
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}
	bool peak[n+1];
	for(i=0;i<=n;i++) peak[i]=false;
	for(i=2;i<n;i++){
		if(arr[i-1]<arr[i] && arr[i]>arr[i+1]) peak[i]=true;
	}
	ll dp[n+1];
	for(i=0;i<=n;i++) dp[i]=0;
	for(i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(peak[i]) dp[i]++;
	}
	ll peaks=LLONG_MIN,l=0;
	//cout<<"peaks\t";
	//for(i=1;i<=n;i++) cout<<peak[i];
	//cout<<endl<<"dp\t";
	//for(i=1;i<=n;i++) cout<<dp[i];
	//cout<<endl;
	for(i=1;i<=n-k+1;i++){
		ll mypeaks = dp[i+k-2]-dp[i];
		if(mypeaks>peaks){
			l=i;
			peaks = mypeaks;
		}
	}
	cout<<peaks+1<<" "<<l<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
