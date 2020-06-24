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
int mat[55][55];
bool vis[55][55];
ll n,m;
bool isvalid(ll x,ll y){
	if(x>=0 && x<n && y>=0 &&y<m) return true;
	return false;
}
void dfs(ll x,ll y,ll& nge){
	vis[x][y]=true;
	if(mat[x][y]==1) return;
	if(mat[x][y]==2) nge++;
	if(isvalid(x-1,y)&&!vis[x-1][y]) dfs(x-1,y,nge);
	if(isvalid(x+1,y)&&!vis[x+1][y]) dfs(x+1,y,nge);
	if(isvalid(x,y-1)&&!vis[x][y-1]) dfs(x,y-1,nge);
	if(isvalid(x,y+1)&&!vis[x][y+1]) dfs(x,y+1,nge);
}
void solve(ll caseno){
	ll i,j,ng=0,nb=0;
	cin>>n>>m;
	mset(mat,0);
	fo(i,0,n){
		fo(j,0,m){
			char ch;
			cin>>ch;
			if(ch=='#') mat[i][j]=1;
			else if(ch=='G') {mat[i][j]=2;ng++;}
			else if(ch=='B') {mat[i][j]=3;nb++;}
			else mat[i][j]=0;
		}
	}
	//if(caseno==57 &&n==1 &&m==5){
		//cout<<n<<m<<endl;
		//fo(i,0,n){
		//fo(j,0,m){
			//cout<<mat[i][j]<<endl;
		//}
	//}
	//}
	//near exit
	if(ng>0){
		if( (isvalid(n-2,m-2)&&mat[n-2][m-2]==3) || 
		    (isvalid(n-2,m-1)&&mat[n-2][m-1]==3) ||
		    (isvalid(n-1,m-2)&&mat[n-1][m-2]==3)){
				cout<<"No"<<endl;
				return;
			}
	}
	//if adjacent b&g
	fo(i,0,n){
		fo(j,0,m){
			if(mat[i][j]==3){
				if((isvalid(i-1,j)&&mat[i-1][j]==2)||
				(isvalid(i,j-1)&&mat[i][j-1]==2)||
				(isvalid(i,j+1)&&mat[i][j+1]==2)||
				(isvalid(i+1,j)&&mat[i+1][j]==2)){
					cout<<"No"<<endl;
				return;
				}  
			}
		}
	}
	//blocking all Bs
	fo(i,0,n){
		fo(j,0,m){
			if(mat[i][j]==3){
				if(isvalid(i+1,j)&&mat[i+1][j]==0) mat[i+1][j]=1;
				if(isvalid(i,j+1)&&mat[i][j+1]==0) mat[i][j+1]=1;
				if(isvalid(i-1,j)&&mat[i-1][j]==0) mat[i-1][j]=1;
				if(isvalid(i,j-1)&&mat[i][j-1]==0) mat[i][j-1]=1;
			}
		}
	}
	//all g exitable
	ll nge=0;
	mset(vis,0);
	dfs(n-1,m-1,nge);
	//cout<<nge<<endl;
	if(nge!=ng){
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
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
