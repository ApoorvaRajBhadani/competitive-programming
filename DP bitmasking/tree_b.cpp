#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
//https://codeforces.com/problemset/problem/337/D example problem
void dfs1(ll start,vector<ll>* edges,ll* in,bool* visited){
	visited[start]=true;
	ll i;
	in[start]=0;
	for(i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			dfs1(adjv,edges,in,visited);
			in[start] = max(in[start],1+in[adjv]);
		}
	}
}
void dfs2(ll start,vector<ll>* edges,ll* in,ll* out,bool* visited){
	visited[start] = true;
	ll i;
	ll mx1=-1,mx2 =-1;
	for(i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			if(in[adjv]>=mx1) {mx2=mx1;mx1=in[adjv];}
			else if(in[adjv]>mx2) mx2=in[adjv];
		}
	}
	for(i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		//cout<<adjv+1<<" "<<visited[adjv]<<endl;
		if(!visited[adjv]){
			ll use = mx1;
			if(in[adjv]==mx1) use=mx2;
			//cout<<adjv+1<<endl;
			out[adjv] = max(1+out[start],2+use);
			dfs2(adjv,edges,in,out,visited);
		}
	}
}
void solve(){
	ll i,j,n;
	cin>>n;
	vector<ll>* edges = new vector<ll>[n];
	fo(i,0,n-1){
		ll u,v;
		cin>>u>>v;
		u--;v--;
		edges[u].pbb(v);
		edges[v].pbb(u);
	}
	ll* in = new ll[n]();
	ll* out = new ll[n]();
	bool* visited = new bool[n]();
	dfs1(0,edges,in,visited);
	memset(visited,0,sizeof(visited[0])*n);
	//fo(i,0,n) visited[i]=false;
	dfs2(0,edges,in,out,visited);
	fo(i,0,n){
		cout<<"node "<<i+1<<endl;
		cout<<in[i]<<" "<<out[i]<<endl;
		cout<<max(in[i],out[i])<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
/*
 * Input
10                       
1 2
1 3
1 4
2 5
2 6
3 7
4 8
7 9
7 10
*/
