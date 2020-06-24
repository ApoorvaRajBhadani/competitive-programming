#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))

void solve(){
	ll i,j,n,m,a,b;
	cin>>n>>m>>a>>b;
	ll mat[n][m];
	ll low = 0,high = a;
	ll row = 0;
	mset(mat,0);
	while(row<n){
		for(i=0;i<b;i++,row++){
			for(j=low;j<high;j++){
				mat[row][j]=1;
				if(j>=m){
					cout<<"NO"<<endl;
					return;
				}
			}
		}
		low+=a;
		high+=a;
	}
	cout<<"YES"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
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
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}
