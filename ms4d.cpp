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
	ll d0=0,d1=0,d2=0;
	fo(i,0,n-1){
		cin>>arr[i];
		if(arr[i]%3==0){
			d0++;
		}else if(arr[i]%3==1){
			d1++;
		}else{
			d2++;
		}
	}
	ll ans = d0;
	ll ttt = min(d1,d2);
	ans+=ttt;
	d1-=ttt;
	d2-=ttt;
	ans+=(d1/3)+(d2/3);
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}
