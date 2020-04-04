#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool mat[1000][1000];
void bfs(ll n,queue<pair<ll,ll>> qu,ll* visited){
	while(!qu.empty()){
		ll visit = qu.front().first;
		//cout<<visit<<" " ;
		ll visitDep = qu.front().second;
		qu.pop();
		for(ll i=0;i<n;i++){
			if(mat[visit][i] && visited[i]==-1){
				qu.push(make_pair(i,visitDep+6));
				visited[i] = visitDep+6;
			}
		}
	}
}
void solve(){
	ll n,m,i;
	memset(mat,false,sizeof(mat));
	cin>>n>>m;
	for(i=0;i<m;i++){
		ll s,d;
		cin>>s>>d;
		s--;d--;
		mat[s][d]=mat[d][s]=true;
	}
	ll s;
	cin>>s;
	s--;
	queue<pair<ll,ll>> qu;
	qu.push(make_pair(s,0));
	ll* visited = new ll[n];
	for(i=0;i<n;i++) visited[i]=-1;
	visited[s] = 0;
	bfs(n,qu,visited);
	for(i=0;i<n;i++){
		if(visited[i]) cout<<visited[i]<<" ";
	}
	cout<<endl;
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
