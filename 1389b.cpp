#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
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
ll arr[200005];
ll answer(ll idx,ll k,ll z){
    if(k==0) return arr[idx];
    ll ans;
    ans=answer(idx+1,k-1,z);
    if(z>0 && k>=2) ans = max(ans,arr[idx-1]+answer(idx,k-2,z-1));
    return ans+arr[idx]; 
}
void solve(ll caseno){
	ll i,j,n,k,z,ans;
    cin>>n>>k>>z;
    fo(i,0,n) cin>>arr[i];
    ans = arr[0] + answer(1,k-1,z);
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
