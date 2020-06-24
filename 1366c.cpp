#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
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
int mat[100][100];
void solve(){
	ll i,j,n,m,ans=0;
	cin>>n>>m;
	mset(mat,-1);
	fo(i,0,n){
		fo(j,0,m){
			cin>>mat[i][j];
		}
	}
	for(i=0,j=n+m-2;i<j;i++,j--){
		ll nz=0,no=0,ii,jj;
		for(ii=i,jj=0;ii>=0;ii--,jj++){
			if(mat[ii][jj]==1)no++;
			else if(mat[ii][jj]==0)nz++;
		}
		for(ii=j,jj=0;ii>=0;ii--,jj++){
			if(mat[ii][jj]==1)no++;
			else if(mat[ii][jj]==0)nz++;
		}
		ans+=min(no,nz);
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
