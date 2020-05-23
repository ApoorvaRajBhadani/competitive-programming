#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void dfs(vector<int>* edges,unordered_set<int> &visited,int start,stack<int> &finishStack){
	visited.insert(start);
	for(int i=0;i<edges[start].size();i++){
		int adjacentVertex = edges[start][i];
		if(visited.count(adjacentVertex)==0){
			dfs(edges,visited,adjacentVertex,finishStack);
		}
	}
	finishStack.push(start);
}
void dfs2(vector<int>* edges,unordered_set<int> &visited,int start,unordered_set<int>* component){
	visited.insert(start);
	component->insert(start);
	for(int i=0;i<edges[start].size();i++){
		int adjv = edges[start][i];
		if(visited.count(adjv)==0){
			dfs2(edges,visited,adjv,component);
		}
	}
}
unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
	unordered_set<int> visited;
	stack<int> finishedVertices;
	for(int i=0;i<n;i++){
		if(visited.count(i)==0){
			//i is not yet visited so start dfs from here
			dfs(edges,visited,i,finishedVertices);
		}
	}
	//now our stack is full
	visited.clear();
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	while(finishedVertices.size()!=0){
		int element = finishedVertices.top();
		finishedVertices.pop();
		if(visited.count(element)==0){
			unordered_set<int>* component = new unordered_set<int>();
			dfs2(edgesT,visited,element,component);
			output->insert(component);
		}
	}
	return output;		
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n;
	vector<int>* edges = new vector<int>[n];
	vector<int>* edgesT = new vector<int>[n];
	cin>>m;
	for(int i=0;i<m;i++){
		int s,d;
		cin>>s>>d;
		edges[s-1].push_back(d-1);
		edgesT[d-1].push_back(s-1);
	}
	unordered_set<unordered_set<int>*>* components = getSCC(edges,edgesT,n);
	unordered_set<unordered_set<int>*>::iterator it = components->begin();
	for(;it!=components->end();it++){
		unordered_set<int>* curcomp = *it;
		unordered_set<int>::iterator it2 = (*it)->begin();
		for(;it2!= (*it)->end();it2++){
			cout<<*it2 +1<<" ";
		}
		cout<<endl;
	}
	delete components;
	delete []edges;
	delete []edgesT;
	return 0;
}
