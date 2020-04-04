#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool dfs(vector<ll>* edges,bool* visited,ll n,int startcolor,int* color,ll start){
	visited[start] = true;
	color[start] = startcolor;
	ll i;
	for(i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			bool check = dfs(edges,visited,n,startcolor^1,color,adjv);
			if(!check) return false;
		}
		if(color[adjv]!=(startcolor^1)) return false;
	}
	return true;
}
bool bipartite(vector<ll>* edges, ll n) {
	int* color = new int[n];
	bool* visited = new bool[n];
	ll i;
	for(i=0;i<n;i++) {
		color[i]=2;
		visited[i] = false;
	}
	//2 means not yet colored
	for(i=0;i<n;i++){
		if(!visited[i]){
			bool check = dfs(edges,visited,n,0,color,i);
			if(!check) return false;
		}
	}
	return true;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll>* edges = new vector<ll>[n];
	for(ll i=0;i<m;i++){
		ll s,d;
		cin>>s>>d;
		s--;d--;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	cout<<(bipartite(edges,n)?"No suspicious bugs found!":"Suspicious bugs found!")<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Scenario #"<<i<<":"<<endl;
		solve();
	}
	return 0;
}
