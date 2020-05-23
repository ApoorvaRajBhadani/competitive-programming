#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007//998244353
#define p_b push_back
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
void solve(){
	ll i,j,n,m,k;
	cin>>n>>k;
	ll arr[n];
	fo(i,0,n-1) cin>>arr[i];
	double dec,inc,ans=-1;
	fo(m,0,1000){
		dec=inc=0;
		fo(i,0,n-1){
			if(arr[i]>=m) dec+=arr[i]-m;
			else inc+=m-arr[i];
		}
		double decp = inc*(double)(100-k)/100;
		cout<<dec<<" "<<decp<<endl;
		if(abs(dec-decp)<=1e-6){
			ans = max(ans,(double)m);
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
