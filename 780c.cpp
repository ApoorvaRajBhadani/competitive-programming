#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int k=1;
void dfs(int start,int lastcolor,int mycolor,vector<int>* edges,int* visited){
	int i,adjv,color=1;
	for(i=0;i<edges[start].size();i++){
		adjv=edges[start][i];
		if(!visited[adjv]){
			if(color==mycolor || color==lastcolor){
				color++;
			}
			if(color==mycolor || color==lastcolor){
				color++;
			}
			visited[adjv]=color;
			k=max(color,k);
			dfs(adjv,mycolor,color,edges,visited);
			color++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,i,s,d;
	cin>>n;
	vector<int>* edges =new vector<int>[n];
	int* visited= new int[n];
	fo(i,0,n-1) visited[i]=0;
	for(i=0;i<n-1;i++){
		cin>>s>>d;
		edges[s-1].push_back(d-1);
		edges[d-1].push_back(s-1);
	}
	visited[0]=1;
	dfs(0,0,1,edges,visited);
	cout<<k<<endl;
	fo(i,0,n-1) cout<<visited[i]<<" ";
	return 0;
}
