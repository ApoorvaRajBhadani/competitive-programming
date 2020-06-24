#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll arr[100005];
void solve(){
	ll i,j,n,x,ans=-1,sum=0;
	cin>>n>>x;
	fo(i,0,n){
		cin>>arr[i];
		sum+=arr[i];
		if(sum%x!=0){
			ans=max(i+1,ans);
		}
	}
	for(i=0;i<n;i++){
		sum-=arr[i];
		if(sum%x!=0){
			ans=max(ans,n-i-1);
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
