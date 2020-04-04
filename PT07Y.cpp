#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

void dfs(vector<ll>* edges,ll start,unordered_set<ll>* component,bool* visited){
	visited[start] = true;
	component->insert(start);
	for(ll i=0;i<edges[start].size();i++){
		if(!visited[edges[start][i]]){
			dfs(edges,edges[start][i],component,visited);
		}
	}
}

unordered_set<unordered_set<ll>*>* getComponents(vector<ll>* edges,ll n){
	bool * visited = new bool[n];
	for(ll i=0;i<n;i++) visited[i] = false;
	
	unordered_set<unordered_set<ll>*>* output = new unordered_set<unordered_set<ll>*>;
	for(ll i =0;i<n;i++){
		if(!visited[i]){
			unordered_set<ll>* component = new unordered_set<ll>;
			dfs(edges,i,component,visited);
			output->insert(component);
		}
	}
	delete [] visited;
	return output;
}

int main(){
	ll n;
	cin>>n;
	vector<ll>* edges = new vector<ll>[n];
	ll m;
	cin>>m;
	for(ll i=0;i<m;i++){
		ll j,k;
		cin>>j>>k;
		edges[j-1].push_back(k-1);
		edges[k-1].push_back(j-1);
	}
	unordered_set<unordered_set<ll>*>* components = getComponents(edges,n);
	ll no_of_comp=components->size();
	/*
	unordered_set<unordered_set<int>*>::iterator it;
	for(it=components->begin();it!=components->end();it++){
		unordered_set<int>* curcomp = *it;
		unordered_set<int>::iterator it2;
		for(it2 = curcomp->begin();it2!=curcomp->end();it2++){
			cout<<*it2+1<<" ";
		}
		delete curcomp;
		cout<<endl;
	}
	*/
	if(no_of_comp == 1 && n-1 == m ) cout<<"YES";
	else cout<<"NO";
	delete components;
	delete []edges;
	return 0;
}




















