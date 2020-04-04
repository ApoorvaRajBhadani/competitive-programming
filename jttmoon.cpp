#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void bfs(vector<ll>* edges,bool* visited,ll n,queue<ll> qu,vector<ll>* compssize){
    ll currcompsize=1;
    while(!qu.empty()){
        ll visit = qu.front();
        qu.pop();
        for(ll i=0;i<edges[visit].size();i++){
            if(!visited[edges[visit][i]]){
                qu.push(edges[visit][i]);
                visited[edges[visit][i]]=true;
                currcompsize++;
            }
        }
    }
    compssize->push_back(currcompsize);
    fo(i,0,n-1){
        if(!visited[i]){
			if(edges[i].size()==0) {
				compssize.push_back(1);
				continue;
			}
            qu.push(i);
            visited[i]=true;
            bfs(edges,visited,n,qu,compssize);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m,i;
    cin>>n>>m;
    vector<ll>* edges= new vector<ll>[n];
    for(i=0;i<m;i++){
        ll s,d;
        cin>>s>>d;
        edges[s].push_back(d);
        edges[d].push_back(s);
    }
    vector<ll>* compssize = new vector<ll>;
    bool* visited = new bool[n];
    fo(i,0,n-1) visited[i]=false;
    queue<ll> qu;
    qu.push(0);
    visited[0]=true;
    bfs(edges,visited,n,qu,compssize);
    ll ans=0,sumofoldvalues=0;
    for(i=0;i<compssize->size();i++){
        ans+=sumofoldvalues*(*compssize)[i];
        sumofoldvalues+=(*compssize)[i];
    }
    cout<<ans;
    return 0;
}
