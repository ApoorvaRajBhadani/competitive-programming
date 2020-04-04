#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool mat[20][20];
bool visited[20][20];
int ans;
int movemt[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
void findAns(int n,int curx,int cury){
	if(curx==n-1&&cury==n-1) {
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int newx = curx + movemt[i][0];
		int newy = cury + movemt[i][1];
		if(newx>=0 && newx<n && newy>=0 && newy<n && !visited[newx][newy] && mat[newx][newy]){
			visited[newx][newy] = true;
			findAns(n,newx,newy);
			visited[newx][newy] = false;
		}
	}
}
void solve(){
	memset(mat,false,sizeof(mat));
	memset(visited,false,sizeof(visited));
	ans=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
			mat[i][j]=!mat[i][j];
		}
	}
	visited[0][0] = true;
	findAns(n,0,0);
	visited[0][0] = false;
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
