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
ll arr[200005],ps[200005],ans[200005];
void solve(ll caseno){
	ll i,j,n,m;
    cin>>n>>m;
    fo(i,0,n) cin>>arr[i];
    sort(arr,arr+n);
    ps[0]=arr[0];
    fo(i,1,n){
        ps[i]=arr[i]+ps[i-1];
    }
    fo(i,0,n){
        ans[i] = ps[i];
        ll toadd = i-m;
        if(toadd>=0) ans[i]+=ans[i-m];
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
