#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll ans;
ll findAns(vector<ll>* edges,bool* visited,ll start){
	visited[start]=1;ll i,childans=0;
	for(i=0;i<edges[start].size();i++){
		ll adjv=edges[start][i];
		if(!visited[adjv]){
			childans+=findAns(edges,visited,adjv);
		}
	}
	//cout<<start<<"s ans is "<<
	ans+=edges[start].size()+childans;
	return edges[start].size()+childans;
}
void solve(){
	ll n,i,s,d;
	cin>>n;
	vector<ll>* edges = new vector<ll>[n];
	for(i=0;i<n-1;i++){
		cin>>s>>d;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	bool* visited = new bool[n];
	fo(i,0,n-1) visited[i]=0;
	ans=1;
	findAns(edges,visited,0);
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
