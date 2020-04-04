#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll distant;
ll mxx=0;
ll dfsLongestLength(vector<ll>* edges,bool* visited,ll start,ll n){
	visited[start] = true;
	ll i,mx=0;
	for(i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			mx = max(mx,dfsLongestLength(edges,visited,adjv,n));
		}
	}
	return mx+1;
}
void findDistant(vector<ll>* edges,bool* visited,ll start,ll distance){
	visited[start] = true;
	ll i,mx=0;
	for(i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			findDistant(edges,visited,adjv,distance+1);
		}
	}
	if(distance > mxx){
		mxx = distance;
		distant = start;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,i;
	cin>>n;
	vector<ll>* edges = new vector<ll>[n];
	for(i=1;i<=(n-1);i++){
		ll s,d;
		cin>>s>>d;
		s--;
		d--;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	ll n0 = edges[0].size();
	ll arr[n0];
	bool* visited = new bool[n];
	for(ll i=0;i<n;i++) visited[i] = false;
	findDistant(edges,visited,0,0);
	/*
	bool* visited = new bool[n];
	for(ll i=0;i<n;i++) visited[i] = false;
	pair<ll,ll> startP = findDistant(edges,visited,0);
	ll start = startP.second;
	cout<<start<<endl;
	*/
	ll start=distant;
	//cout<<start<<endl;
	n0 = edges[start].size();
	ll mx=0;
	for(ll i=0;i<n;i++) visited[i] = false;
	visited[start] = true;
	for(i=0;i<n0;i++){
		ll findLongestLength = dfsLongestLength(edges,visited,edges[start][i],n);
		mx=max(findLongestLength,mx);
	}
	cout<<mx;
	return 0;
}
