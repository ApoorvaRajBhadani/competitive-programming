#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool edges[100][100];
int n,ans;
int findEdgeChilds(bool* visited,int start){
	visited[start]=true;
	int childs=0;
	for(int i=0;i<n;i++){
		if(edges[start][i] && !visited[i]){
			int child=findEdgeChilds(visited,i)+1;
			if(child%2==0) ans++;
			childs+=child;
		}
	}
	//cout<<start+1<<" have "<<childs<<" child."<<endl;
	return childs;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int m,i;
	cin>>n>>m;
	memset(edges,false,sizeof(edges));
	for(i=0;i<m;i++){
		int s,d;
		cin>>s>>d;
		s--;d--;
		edges[s][d]=edges[d][s]=true;
	}
	ans=0;
	bool* visited = new bool[n];
	fo(i,0,n-1) visited[i] = false;
	findEdgeChilds(visited,0);
	cout<<ans;
	return 0;
}
