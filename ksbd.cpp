#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
double mat[1000][1000];
void solve(){
	ll w,h,l,u,r,d,i,j;
	cin>>w>>h>>l>>u>>r>>d;
	w--;h--;l--;u--;r--;d--;
	memset(mat,0,sizeof(mat));
	mat[0][0]=1;
	for(i=0;i<=(w+h);i++){
		for(j=i-w<0?0:i-w;j<=i;j++){
			//cout<<"at "<<j<<" "<<i-j<<endl;
			if(j>=h && (i-j)>=w) break;
			//if(j>=u && j<=d && (i-j)>=l && (i-j)<=r)mat[j][i-j]=0;
			if(i-j+1 >w && j+1<=h){
				//rightmost
				mat[j+1][i-j]+=mat[j][i-j];
			}else if(i-j+1<=w &&j+1>h){
				//bottom most
				mat[j][i-j+1] += mat[j][i-j];
			}else if(i-j+1<=w && j+1<=h){
				mat[j][i-j+1] += mat[j][i-j]/2;
				mat[j+1][i-j] += mat[j][i-j]/2;
			}
		}
	}
	cout<<endl;
	for(i=0;i<=h;i++){
		for(j=0;j<=w;j++){
			cout<<mat[i][j]<<"\t\t";
		}
		cout<<endl;
	}
	if(mat[h][w]==0) cout<<"0.0"<<endl;
	else cout<<mat[h][w]<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
