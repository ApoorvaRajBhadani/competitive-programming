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
	ll i,j,N,k;
	cin>>N>>k;
	ll low = 1,high = N,mid,val;
	while(low<=high){
		mid = (low+high)>>1;
		val = ((mid+1)*(mid))/2 - (N-mid);
		if(val>k){
			high = mid-1;
		}else if(val<k){
			low = mid+1;
		}else{
			cout<<(N-mid)<<endl;
			return;
		}
	}
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
