#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int edge[3000][3000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(edge,0,sizeof(edge));
	int n,m,start,i;
	ll ans=0;
	cin>>n>>m;
	for(i=0;i<m;i++){
		int f,s,w;
		cin>>f>>s>>w;
		f--;s--;
		if(edge[f][s]==0) {edge[f][s]=edge[s][f]=w;}
		else if(edge[f][s]>w) {cout<<"here"<<endl;edge[f][s]=edge[s][f]=w;}
	}
	cin>>start;
	start--;
	int parent[n],weight[n],count=0;
	bool visited[n];
	parent[start]=-1;
	for(i=0;i<n;i++) {weight[i]=INT_MAX;visited[i]=false;}
	weight[start]=0;
	while(count<n){
		int curnode=-1,wgt=INT_MAX;
		for(i=0;i<n;i++){
			if(!visited[i] && weight[i]<wgt){
				curnode = i;
				wgt = weight[i];
			}
		}
		visited[curnode] = true;
		count++;
		for(i=0;i<n;i++){
			if(edge[curnode][i]>0 && !visited[i] && (weight[i]> edge[curnode][i])){
				parent[i] = curnode;
				weight[i] = edge[curnode][i];
			}
		}
	}
	for(i=0;i<n;i++) {
		if(i==start) continue;
		ans+= weight[i];
		//cout<<weight[i]<<endl;
	}
	cout<<ans;
	return 0;
}

























