#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool dfs(vector<int>* edges,bool* visited,int n,int startcolor,int* color,int start){
	visited[start] = true;
	color[start] = startcolor;
	int i;
	for(i=0;i<edges[start].size();i++){
		int adjv = edges[start][i];
		if(!visited[adjv]){
			bool check = dfs(edges,visited,n,startcolor^1,color,adjv);
			if(!check) return false;
		}
		if(color[adjv]!=(startcolor^1)) return false;
	}
	return true;
}
bool bipartite(vector<int>* edges, int n) {
	int* color = new int[n];
	bool* visited = new bool[n];
	ll i;
	for(i=0;i<n;i++) {
		color[i]=2;
		visited[i] = false;
	}
	//2 means not yet colored
	for(i=0;i<n;i++){
		if(!visited[i]){
			bool check = dfs(edges,visited,n,0,color,i);
			if(!check) return false;
		}
	}
	return true;
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<int>* edges = new vector<int>[n];
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int j, k;
			cin >> j >> k;
			edges[j].push_back(k);
			edges[k].push_back(j);
		}
		bool ans = bipartite(edges, n);
		delete [] edges;
		if (ans) {
			cout << "BICOLORABLE." << endl;
		} else {
			cout << "NOT BICOLORABLE." << endl;
		}
	}
}
