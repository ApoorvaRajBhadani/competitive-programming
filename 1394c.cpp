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
ll a[205],b[205];
ll axb[205][205];
void solve(ll caseno){
	ll i,j,n,m,ans=0,v;
    cin>>n>>m;
    fo(i,0,n) cin>>a[i];
    fo(i,0,m) cin>>b[i];
    fo(i,0,n){
        fo(j,0,m){
            axb[i][j]=a[i]&b[j];
        }
    }
    ll p = pow(2,30);
    for(;p>=1;p/=2){
        bool comp=false;
        for(i=0;i<n;i++){
            bool mycomp=true;
            for(j=0;j<m;j++){
                if(axb[i][j]==-1) continue;
                if((axb[i][j]&p)==0) mycomp=false;
            }
            if(mycomp) comp=true;
        }
        if(comp) ans+=p;
        else{
            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    if(axb[i][j]==-1) continue;
                    if((axb[i][j]&p)>0) axb[i][j]=-1;
                }
            }
        }
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
