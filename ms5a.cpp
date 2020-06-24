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
	ll i,j,q,n,ans=0,its=0;
	cin>>q;
	vector<ll> mnarr,mxarr;
	for(j=0;j<q;j++){
		cin>>n;
		ll mn=INT_MAX,mx=-1,a;
		bool itself=false;
		for(i=0;i<n;i++){
			cin>>a;
			mn = min(a,mn);
			mx = max(a,mx);
			if(i>0){
				if(a>mn) itself = true;
			}
		}
		if(itself){
			ans+=q;
			its++;
		}
		else{
			mnarr.pbb(mn);
			mxarr.pbb(mx);
		}
	}
	sort(all(mxarr));
	for(i=0;i<mnarr.size();i++){
		ans+=its;
		auto ittt = upper_bound(all(mxarr),mnarr[i]);
		ans+= mxarr.end()-ittt;
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
