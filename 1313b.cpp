#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
char mat[1505][35];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,k,i,j,jj,jjj,c=0;
	cin>>n>>k;
	for(i=0;i<n;i++){
		string s;
		cin>>s;
		for(j=0;j<k;j++){
			mat[i][j]=s[j];
		}
	}
	for(i=0;i<n-2;i++){
		for(j=i+1;j<n-1;j++){
			for(jj=j+1;jj<n;jj++){
				bool pos=true;
				for(jjj=0;jjj<k;jjj++){
					if( !((mat[i][jjj]== mat[j][jjj]&& mat[j][jjj]==mat[jj][jjj])
					      || (mat[i][jjj]!= mat[j][jjj]&& mat[j][jjj]!=mat[jj][jjj] &&mat[jj][jjj]!=mat[i][jjj]))) {
							  pos=false;
							  break;
						  }
				}
				if(pos) {
					c++;
					//cout<<i<<" "<<j<<" "<<jj<<endl;
				}
			}
		}
	}
	cout<<c<<endl;
	return 0;
}
