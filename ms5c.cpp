#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))

void solve(){
	ll i,j,n;
	cin>>n;
	ll arr[n];
	fo(i,0,n-1) cin>>arr[i];
	ll dp[n];
	dp[0]=1;
	vector<ll> oness;
	ll ans= 1;
	fo(i,1,n-1){
		if(arr[i]>arr[i-1]){
			dp[i]=dp[i-1]+1;
		}else{
			dp[i]=1;
			oness.pbb(i);
		}
		ans = max(ans,dp[i]);
	}
	oness.pbb(n);
	//for(auto num:dp) cout<<num<<" ";cout<<endl;
	fo(i,1,n-2){
		if(dp[i-1]-dp[i+1]==-2) continue;
		if(arr[i+1]>arr[i-1]){
			auto itt = upper_bound(all(oness),i+1);
			if(dp[i]==1)ans = max(ans,dp[i-1]+dp[*itt -1]-1);
			if(dp[i+1]==1)ans = max(ans,dp[i-1]+dp[*itt -1]);
			//cout<<i-1<<" "<<*itt-1<<endl;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
