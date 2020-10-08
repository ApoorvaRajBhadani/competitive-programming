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
void solve(ll caseno){
	ll i,j,n,k;
    cin>>n>>k;
	int mat[n][n];
	fo(i,0,n) fo(j,0,n) mat[i][j]=0;
	ll x=0,y=0,diff=0;
	while(k--){
		mat[x][y]=1;
		//cout<<x<<" "<<y<<endl;
		x++;y++;
		y%=n;
		if(x==n) x=0,y=(y+1)%n;
	}
	ll mxr=0,mnr=INT_MAX,mxc=0,mnc=INT_MAX,fa;
	fo(i,0,n){
		ll myrsum=0;
		fo(j,0,n){
			myrsum+=mat[i][j];
		}
		mxr=max(mxr,myrsum);
		mnr=min(mnr,myrsum);
	}
	fo(j,0,n){
		ll mycsum=0;
		fo(i,0,n){
			mycsum+=mat[i][j];
		}
		mxc=max(mycsum,mxc);
		mnc=min(mycsum,mnc);
	}
	fa=(mxr-mnr)*(mxr-mnr)+(mxc-mnc)*(mxc-mnc);
	cout<<fa<<endl;
	fo(i,0,n){
		fo(j,0,n){
			cout<<mat[i][j];
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
