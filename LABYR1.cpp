#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool mat[1005][1005],visited[1005][1005];
ll distantx,distanty,mxx,r,c;
int movemt[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
void findDistant(ll startx,ll starty,ll distance){
	visited[startx][starty]=true;
	if(distance>mxx){
		mxx=distance;
		distantx=startx;
		distanty=starty;
	}
	//cout<<"now at "<<startx<<" "<<starty<<endl;
	ll i,newx,newy;
	for(i=0;i<4;i++){
		newx=movemt[i][0]+startx;
		newy=movemt[i][1]+starty;

			if(!visited[newx][newy]&&mat[newx][newy] &&newx>=0 && newx<r && newy>=0 &&newy<c){
				findDistant(newx,newy,distance+1);
			}

	}
}
void solve(){
	ll i,j,ndx,ndy;
	string row;char block;
	cin>>c>>r;
	memset(mat,false,sizeof(mat));
	for(i=0;i<r;i++){
		cin>>row;
		for(j=0;j<c;j++){
			block = row[j];
			if(block=='.') {
				mat[i][j]=true;
				ndx=i;ndy=j;
			}
		}
	}
	memset(visited,0,sizeof(visited));
	mxx=-1;distantx=0;distanty=0;
	findDistant(ndx,ndy,0);
	memset(visited,0,sizeof(visited));
	mxx=-1;
	findDistant(distantx,distanty,0);
	cout<<mxx;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cout<<"Maximum rope length is ";
		solve();
		cout<<"."<<endl;
	}
	return 0;
}
