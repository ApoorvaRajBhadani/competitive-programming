#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int mov[4][2] = { {-1,0},{0,-1},{1,0},{0,1}};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int r,c,i,j;
	cin>>r>>c;
	char mat[r][c];
	for(i=0;i<r;i++){
		string s;
		cin>>s;
		for(j=0;j<c;j++){
			mat[i][j]=s[j];
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(mat[i][j]=='S'){
			for(int k=0;k<4;k++){
				int x=i+mov[k][0];
				int y=j+mov[k][1];
				if(x>=0 && y>=0 && x<r && y<c){
					if(mat[x][y]=='W'){
						cout<<"No";
						return 0;
					}
					else if(mat[x][y]=='.'){
						mat[x][y]='D';
					}
				}
			}
			}
		}
	}
	cout<<"Yes"<<endl;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cout<<mat[i][j];
		}
		cout<<endl;
	}
	return 0;
}
