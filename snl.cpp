#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int findAns(int* takemeto,queue<pair<int,int>> qu,bool* visited){
	while(!qu.empty()){
		int visit = qu.front().first , visitDep = qu.front().second;
		//cout<<visit<<endl;
		qu.pop();
		if(visit==100) return visitDep;
		for(int i=1;i<=6;i++){
			int newpos = visit+i;
			if(newpos>100) continue;
			newpos = takemeto[newpos];
			if(!visited[newpos]){
				qu.push(make_pair(newpos,visitDep+1));
				visited[newpos]=true;
			}
		}
	}
	return -1;
}
void solve(){
	int n,m,i;
	cin>>n;
	int* takemeto=new int[101];
	bool* visited= new bool[101];
	for(i=1;i<=100;i++) {
		takemeto[i] = i;
		visited[i]=false;
	}
	for(i=0;i<n;i++){
		int from,to;
		cin>>from>>to;
		takemeto[from]=to;
	}
	cin>>m;
	for(i=0;i<m;i++){
		int from,to;
		cin>>from>>to;
		takemeto[from]=to;
	}
	queue<pair<int,int>> qu;
	qu.push(make_pair(1,0));
	visited[1]=true;
	int ans = findAns(takemeto,qu,visited);
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
