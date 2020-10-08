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
ll n,m;
ll mat[305][305];
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,-1,1};
ll findnb(ll i,ll j){
    ll ans=0;
    for(ll ii=0;ii<4;ii++){
        ll ni=i+dx[ii];
        ll nj=j+dy[ii];
        if(ni>=0 && ni<n &&nj>=0 &&nj<m) ans++;
    }
    return ans;
}
void solve(ll caseno){
	ll i,j,val;
    bool ans=true;
    cin>>n>>m;
    fo(i,0,n){
        fo(j,0,m){
            cin>>val;
            ll nb=findnb(i,j);
           // cout<<i<<j<<nb<<endl;
            if(val>nb) ans=false;
            else mat[i][j]=nb;
        }
    }
    if(ans==false){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    fo(i,0,n){
        fo(j,0,m){
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
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
