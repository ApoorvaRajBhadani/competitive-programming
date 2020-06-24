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
	ll i,j,n,s,x,y;
	cin>>n>>s;
	s--;//0 based nodes considered
	vector<ll>* edges = new vector<ll>[n];
	fo(i,0,n-1){
		ll u,v;
		cin>>u>>v;
		u--;v--;
		edges[u].pbb(v);
		edges[v].pbb(u);
	}
	x = edges[s].size();
	y = n-1-x;
	//s is a leaf
	if(x==0||x==1){
		cout<<"Ayush"<<endl;
		return;
	}
	//s is not a leaf
	if(y%2==0){
		if(x%2==1){
			//a wins
			cout<<"Ayush"<<endl;
		}else{
			//a loses
			cout<<"Ashish"<<endl;
		}
	}else{
		if((x+1)%2==1){
			//a wins
			cout<<"Ayush"<<endl;
		}else{
			//a loses
			cout<<"Ashish"<<endl;
		}
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
