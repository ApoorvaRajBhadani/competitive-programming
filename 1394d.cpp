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
vi chota,bada;
ll chotaps[200005];
ll badaps[200005];
void solve(ll caseno){
    mset(chotaps,0);
    mset(badaps,0);
	ll i,j,n,d,m,ans=0;
    cin>>n>>d>>m;
    fo(i,0,n){
        cin>>j;
        if(j>m) bada.pbb(j);
        else chota.pbb(j);
    }
    sort(all(chota),greater<ll>());
    sort(all(bada),greater<ll>());
    ll nc=chota.size(),nb=bada.size();
    if(nc>0){
        chotaps[0]=chota[0];
        fo(i,1,nc) chotaps[i]=chota[i]+chotaps[i-1];
    }
    if(nb>0){
        badaps[0]=bada[0];
        fo(i,1,nb) badaps[i]=bada[i]+badaps[i-1];
    }
    ll b,s=nc;
    ans = (s?chotaps[s-1]:0);
    for(b=1;b<=nb;b++){
        ll days = 1ll+(b-1ll)*(d+1ll);
        if(days>n) continue;
        s = n-days;
        if( s<0 ) continue;
        s= min(s,nc);
        ll myans = (b?badaps[b-1]:0);
        myans+= (s?chotaps[s-1]:0);
        ans = max(ans,myans);
    }
    cout<<ans<<endl;
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
