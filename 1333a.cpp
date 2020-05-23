#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m,i,j;
		cin>>n>>m;
		bool mat[n+1][m+1],prev,last,isev = (n%2==0||m%2==0)?1:0;
		mat[0][1]=1;
		for(i=1;i<=n;i++){
			last = mat[i-1][1];
			for(j=1;j<=m;j++){
				last = last^1;
				if(last==1){
					mat[i][j]=last;
				}else{
					mat[i][j]=last;
				}
				//cout<<(mat[i][j]?'W':'B');
			}
			//cout<<endl;
		}
		if(isev){
			if(mat[n][m]){
				mat[n][m]=0;
			}else if(mat[n][m-1]){
				mat[n][m-1]=0;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cout<<(mat[i][j]?'W':'B');
			}
			cout<<endl;
		}
	}
	return 0;
}
