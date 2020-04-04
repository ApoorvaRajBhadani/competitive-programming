#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int dist[182][182],r,c;
bool visited[182][182];
int movemt[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int setDist(int startx,int starty){
	if(visited[startx][starty]) return dist[startx][starty];
	int mn=INT_MAX,i,newx,newy;
	visited[startx][starty]=true;
	for(i=0;i<4;i++){
		newx=startx+movemt[i][0];
		newy=starty+movemt[i][1];
		if(newx>=0 && newx<r && newy>=0 && newy<c){
			//cout<<"find "<<newx<<" "<<newy<<endl;
				setDist(newx,newy);
				mn = min(dist[newx][newy],mn);
		}
	}
	dist[startx][starty]=mn+1;
	cout<<"at "<<startx<<" "<<starty<<" "<<mn+1<<endl;
	return mn+1;
}
void solve(){
	memset(dist,INT_MAX,sizeof(dist));
	memset(visited,false,sizeof(visited));
	ll i,j;
	string row;
	cin>>r>>c;
	for(i=0;i<r;i++){
		cin>>row;
		for(j=0;j<c;j++){
			if(row[j]=='1'){
				visited[i][j]=true;
				dist[i][j]=0;
			}
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(!visited[i][j]){
				setDist(i,j);
			}
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
