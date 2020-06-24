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

void solve(){
	ll i,j;
	long double n,m,x,y;
	cin>>n>>m>>x>>y;
	bool pos=true;
	if(true){
		long double t = ((y-1)-(x-1))/(2*(n-1));
		cout<<t<<endl;
		if(floor(t)==ceil(t)&&t>=0) pos=false;
	}
	if(true){
		long double t= ((((y-1)-(n-x))/(n-1))-1)/2.0;
		cout<<t<<endl;
		if(floor(t)==ceil(t)&&t>=0) pos=false;
	}
	if(true){
		long double t= ((m-1)+(x-1)-(m-y))/(2*(m-1));
		cout<<t<<endl;
		if(floor(t)==ceil(t)&&t>=0) pos=false;
	}
	if(true){
		long double t = ((((m-1)+(x-1)-(y-1))/(m-1))-1)/2.0;
		cout<<t<<endl;
		if(floor(t)==ceil(t)&&t>=0) pos=false;
	}
	if(pos){
		cout<<"Farewell"<<endl;
	}else cout<<"BestWishes"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
