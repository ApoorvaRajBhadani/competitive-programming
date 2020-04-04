#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

void dfs(vector<ll>* edges,bool * visited,ll start,unordered_set<ll>* component){
	visited[start] = true;
	component->insert(start);
	ll i;
	for(i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			dfs(edges,visited,adjv,component);
		}
	}
}

unordered_set<unordered_set<ll>*>* getComponents(vector<ll>* edges,ll n){
	bool* visited = new bool[n];
	ll i;
	for(i=0;i<n;i++) visited[i] = false;
	
	unordered_set<unordered_set<ll>*>* output = new unordered_set<unordered_set<ll>*>;
	for(i=0;i<n;i++){
		if(!visited[i]){
			unordered_set<ll>* component = new unordered_set<ll>;
			dfs(edges,visited,i,component);
			output->insert(component);
		}
	}
	delete []visited;
	return output;
}

void solve(){
	ll n,m,i;
	cin>>n>>m;
	vector<ll>* edges = new vector<ll>[n];
	for(i=0;i<m;i++){
		ll s,d;
		cin>>s>>d;
		s--;d--;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	ll arr[n],mx=0;
	for(i=0;i<n;i++) cin>>arr[i];
	unordered_set<unordered_set<ll>*>* components = getComponents(edges,n);
	unordered_set<unordered_set<ll>*>::iterator it;
	for(it = components->begin();it!=components->end();it++){
		unordered_set<ll>* comp = *it;
		unordered_set<ll>::iterator it2;
		ll sum =0;
		for(it2=comp->begin();it2!=comp->end();it2++){
			sum+=arr[*it2];
		}
		mx = max(sum,mx);
	}
	cout<<mx<<endl;
	delete components;
	delete []edges;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
