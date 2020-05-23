#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int mat[9][9];
int pos[9][2] = {{8,0},{7,3},{6,6},{5,1},{4,4},{3,7},{2,2},{1,5},{0,8}};
void solve(){
	ll i,j;
	string s;
	for(i=0;i<9;i++){
		cin>>s;
		for(j=0;j<9;j++){
			char c = s[j];
			mat[i][j] = c-'0';
		}
	}
	for(i=0;i<9;i++){
		if(mat[pos[i][0]][pos[i][1]] == 5) mat[pos[i][0]][pos[i][1]]=4;
		else mat[pos[i][0]][pos[i][1]] = 10 - mat[pos[i][0]][pos[i][1]];
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<mat[i][j];
		}
		cout<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
