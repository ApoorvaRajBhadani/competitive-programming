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
ll arr[200005],w[200005];
void solve(ll caseno){
	ll i,j,n,k;
    cin>>n>>k;
    fo(i,0,n) cin>>arr[i];
    fo(i,0,k) cin>>w[i];
    sort(arr,arr+n);
    sort(w,w+k,greater<ll>());
    vi vec[k];
    j=n-1;
    for(i=k-1;i>=0;i--){
        vec[i].pbb(arr[j--]);
        w[i]--;
    }
    j=0;
    for(i=0;i<k;i++){
        while(w[i]--){
            vec[i].pbb(arr[j++]);
        }
    }
    ll ans=0;
    for(i=0;i<k;i++){
        sort(all(vec[i]));
        ans+=vec[i][0];
        ans+=vec[i][vec[i].size()-1];
    }
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
