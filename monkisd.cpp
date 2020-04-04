#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

ll bfs(vector<ll>* edges,bool* visited,queue<pair<ll,ll>> qu,ll endd){
	ll i;
	while(!qu.empty()){
		ll visit = qu.front().first;
		ll visitedDep = qu.front().second;
		qu.pop();
		if(visit == endd){
			return visitedDep;
		}
		for(i=0;i<edges[visit].size();i++){
			ll adjv = edges[visit][i];
			if(!visited[adjv]){
				qu.push(make_pair(adjv,visitedDep+1));
				visited[adjv]=true;
			}
		}
	}
	return 0;
}

void solve(){
	ll n,e,i;
	cin>>n>>e;
	vector<ll>* edges = new vector<ll>[n];
	for(i=0;i<e;i++){
		ll s,d;
		cin>>s>>d;
		s--;d--;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	bool* visited = new bool[n];
	for(ll i=0;i<n;i++) visited[i] = false;
	queue<pair<ll,ll>> qu;
	qu.push(make_pair(0,0));
	visited[0] = true;
	cout<<bfs(edges,visited,qu,n-1)<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
