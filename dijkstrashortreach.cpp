#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int edges[3000][3000];
void solve(){
	memset(edges,0,sizeof(edges));
	int n,m,i;
	cin>>n>>m;
	for(i=0;i<m;i++){
		int s,d,w;
		cin>>s>>d>>w;
		s--;d--;
		if(edges[s][d]==0){
			edges[s][d]=edges[d][s]=w;
		}else if(edges[s][d]>w){
			edges[s][d]=edges[d][s]=w;
		}
	}
	int start;
	cin>>start;start--;
	int dist[n];bool visited[n];
	fo(i,0,n-1){
		visited[i]=false;
		dist[i]=-1;
	}
	dist[start]=0;
	int prevnode=-1;
	while(true){
		int wgt=INT_MAX,curnode=-1;
		for(i=0;i<n;i++){
			if(!visited[i] && dist[i]<wgt && dist[i]!=-1){
				curnode = i;
				wgt = dist[i];
			}
		}
		if(-1==curnode) break;
		//cout<<curnode<<endl;
		visited[curnode] = true;
		bool mila = false;
		//update neighbours weight
		for(i=0;i<n;i++){
			if(!visited[i]&&edges[curnode][i]>0 && ((dist[curnode]+edges[curnode][i]<dist[i]) || dist[i]==-1)){
				dist[i]= dist[curnode]+edges[curnode][i];
				mila = true;
			}
		}
		prevnode = curnode;
	}
	fo(i,0,n-1) {
		if(i==start) continue;
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
