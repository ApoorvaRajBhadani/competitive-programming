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
	ll i,j,n,prev,sum=0;
	cin>>n;
	fo(i,0,n){
		cin>>arr[i];
	}
	int type;
	if(arr[1]>arr[0]) type=1;
	else type=-1;
	vector<ll> ans;
	prev=arr[0];
	ans.pbb(arr[0]);
	for(i=1;i<n-1;i++){
		if(type==1){
			if(arr[i+1]>arr[i]) continue;
			else{
				sum+=abs(prev-arr[i]);
				ans.pbb(arr[i]);
				prev=arr[i];
				type=-1;
			}
		}else if(type==-1){
			if(arr[i+1]<arr[i]) continue;
			else{
				sum+=abs(prev-arr[i]);
				ans.pbb(arr[i]);
				prev=arr[i];
				type=1;
			}
		}
	}
	sum+=abs(prev-arr[n-1]);
	ans.pbb(arr[i]);
	cout<<ans.size()<<endl;
	for(auto num:ans) cout<<num<<" ";
	cout<<endl;
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
