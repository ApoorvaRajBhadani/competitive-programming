#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void bfs(vector<int>* edges,bool* visited,queue<int> qu,int* depth){
	while(!qu.empty()){
		int visit=qu.front();
		qu.pop();
		int curdep = depth[visit];
		for(int i=0;i<edges[visit].size();i++){
			int adjv = edges[visit][i];
			if(!visited[adjv]){
				visited[adjv]=1;
				depth[adjv]=curdep+1;
				qu.push(adjv);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,i;
	cin>>n;
	vector<int>* edges = new vector<int>[n];
	bool* visited = new bool[n];
	int* depth = new int[n];
	for(i=0;i<n-1;i++){
		visited[i]=0;
		int s,d;
		cin>>s>>d;
		s--;d--;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	visited[n-1]=0;visited[0]=1;
	queue<int> qu;
	depth[0] = 0;
	qu.push(0);
	bfs(edges,visited,qu,depth);
	bool ans = true;int curdep=0;
	//fo(i,0,n-1) cout<<i+1<<" depth is "<<depth[i];
	for(i=0;i<n;i++){
		int v;
		cin>>v;
		v--;
		if(depth[v]<curdep) ans=0;
		curdep=depth[v];
	}
	cout<<(ans?"Yes":"No");
	return 0;
}
