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
bool mat[55][55];
void solve(){
	ll i,j,n,m;
	cin>>n>>m;
	mset(mat,0);
	fo(i,0,n){
		fo(j,0,m){
			cin>>mat[i][j];
		}
	}
	ll rcnt=0,ccnt=0,cnt=0;
	fo(i,0,n){
		bool pos=true;
		fo(j,0,m){
			if(mat[i][j]==true) pos=false;
		}
		if(pos) rcnt++;
	}
	fo(j,0,m){
		bool pos=true;
		fo(i,0,n){
			if(mat[i][j]==true) pos=false;
		}
		if(pos) ccnt++;
	}
	cnt=min(rcnt,ccnt);
	if(cnt%2==0){
		cout<<"Vivek"<<endl;
	}else{
		cout<<"Ashish"<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
