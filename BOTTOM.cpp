#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

void dfs(vector<int>* edges,bool* visited,int start,stack<int>& finishedVertices){
    visited[start]=true;
    for(int i=0;i<edges[start].size();i++){
        int adjv = edges[start][i];
        if(!visited[adjv]){
            dfs(edges,visited,adjv,finishedVertices);
        }
    }
    finishedVertices.push(start);
}

void dfs2(vector<int>* edges,bool* visited,int start,unordered_set<int>* component){
    visited[start]=true;
    component->insert(start);
    for(int i=0;i<edges[start].size();i++){
        int adjv = edges[start][i];
        if(!visited[adjv]){
            dfs2(edges,visited,adjv,component);
        }
    }
}
unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
    stack<int> finishedVertices;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++) visited[i]=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(edges,visited,i,finishedVertices);
        }
    }
    
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=0;i<n;i++) visited[i]=false;
    while(finishedVertices.size()!=0){
        int element = finishedVertices.top();
        finishedVertices.pop();
        if(!visited[element]){
            unordered_set<int>* component = new unordered_set<int>();
            dfs2(edgesT,visited,element,component);
            output->insert(component);
        }
    }
    return output;
}


void solve(int n){
    int e;
    cin>>e;
    vector<int>* edges = new vector<int>[n];
    vector<int>* edgesT = new vector<int>[n];
    for(int i=0;i<e;i++){
        int s,d;
        cin>>s>>d;
        edges[s-1].push_back(d-1);
        edgesT[d-1].push_back(s-1);
    }
    unordered_set<unordered_set<int>*>* output = getSCC(edges,edgesT,n);
    unordered_set<unordered_set<int>*>::iterator it;
    vector<int> compele;
    for(it=output->begin();it!=output->end();it++){
        unordered_set<int>* comp = *it;
        unordered_set<int>::iterator it2;
        bool flag = true;
        for(it2=comp->begin();it2!=comp->end() && flag;it2++){
            for(int i=0;i<edges[*it2].size();i++){
                if(comp->count(edges[*it2][i])==0) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            for(it2=comp->begin();it2!=comp->end();it2++) compele.push_back(*it2);
        }
    }
    sort(compele.begin(),compele.end());
    for(auto itt=compele.begin();itt!=compele.end();itt++) cout<<*itt+1<<" ";
    cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
    while(true){
    cin>>n;
    if(!n) break;
    solve(n);
    }
	return 0;
}
