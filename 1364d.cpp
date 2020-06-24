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
vector<ll> cycle;
void cyclefind(ll start,ll end,vector<ll>* edges,ll n){
	queue<ll> qu;
	bool* vis=new bool[n]();
	map<ll,ll> mp;
	qu.push(start);
	mp[start]=-1;
	vis[start]=true;
	//cout<<start<<" "<<end<<endl;
	while(!qu.empty()){
		ll visit=qu.front();
		qu.pop();
		if(visit==end) break;
		for(auto adjv:edges[visit]){
			if(visit==start&&adjv==end) continue;
			//cout<<visit<<"->"<<adjv<<endl;
			if(!vis[adjv]){
				qu.push(adjv);
				mp[adjv]=visit;
				vis[adjv]=true;
			}
		}
	}
	cycle.clear();
	while(mp[end]!=-1){
		cycle.pbb(end);
		end=mp[end];
	}
	cycle.pbb(end);
}
void dfs(ll start,ll par,bool* vis,vector<ll>* edges,ll n,bool& cycled){
	vis[start]=true;
	//cout<<start<<endl;
	for(auto adjv:edges[start]){
		if(!vis[adjv]){
			//cout<<"he1lo "<<start<<""<<par<<" "<<adjv<<endl;
			dfs(adjv,start,vis,edges,n,cycled);
		}else if(adjv!=par&&vis[adjv]){
			//back edge
			if(!cycled) {
				//cout<<"he2lo "<<start<<""<<par<<" "<<adjv<<endl;
				cyclefind(adjv,start,edges,n);
				cycled=true;
			}
		}
	}
}
vector<ll> color[2];
void bicolor(ll start,ll par,ll prevcol,vector<ll>* edges){
	ll mycol=1-prevcol;
	color[mycol].pbb(start);
	for(auto adjv:edges[start]){
		if(adjv==par) continue;
		bicolor(adjv,start,mycol,edges);
	}
}
void solve(){
	ll i,j,n,m,k;
	cin>>n>>m;
	vector<ll>* edges=new vector<ll>[n];
	fo(i,0,m){
		ll u,v;
		cin>>u>>v;
		u--;v--;
		edges[u].pbb(v);
		edges[v].pbb(u);
	}
	bool* vis=new bool[n];
	fo(i,0,n) vis[i]=false;
	bool cycled=false;
	dfs(0,-1,vis,edges,n,cycled);
	k=ceil(sqrt((double)n));
	if(cycle.size()<=k&&cycle.size()>=1) {
		cout<<2<<endl;
		cout<<cycle.size()<<endl;
		for(auto node:cycle) cout<<node+1<<" ";
	}else if(cycle.size()>k){
		j=0;
		cout<<1<<endl;
		for(i=1;i<=k;i++){
			cout<<cycle[j]+1<<" ";
			j+=2;
		}
	}else{
	//bicolor
	bicolor(0,-1,1,edges);
	//cout<<color[0].size()<<endl;
	//cout<<color[1].size()<<endl;
	if(color[0].size()>=color[1].size()){
		cout<<1<<endl;
		fo(i,0,k){
			cout<<color[0][i]+1<<" ";
		}
	}else{
		cout<<1<<endl;
		fo(i,0,k){
			cout<<color[1][i]+1<<" ";
		}
	}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
