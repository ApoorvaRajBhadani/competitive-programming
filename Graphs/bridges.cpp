#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll curr_time = 0;
void BridgeUtil(vector<ll>* edges,ll start,bool* visited,ll* disc,ll* low,ll* parent){
	//ll children = 0;
	visited[start]=true;
	disc[start] = low[start] = ++curr_time;
	for(ll adjv:edges[start]){
		if (!visited[adjv]) 
        { 
            //children++; 
            parent[adjv] = start; 
            BridgeUtil(edges,adjv, visited, disc, low, parent); 
            low[start]  = min(low[start], low[adjv]);  
            //if (parent[start] == -1 && children > 1) 
               //ap[start] = true; 
            //if (parent[start] != -1 && low[adjv] >= disc[start]) 
               //ap[start] = true;
            if(low[adjv]>disc[start]) 
				cout<<start<<" "<<adjv<<endl;
        } 
        else if (adjv != parent[start]) 
            low[start]  = min(low[start], disc[adjv]);
	}
}
void findBridges(vector<ll>* edges,ll n){
	ll i;
	bool *visited = new bool[n]; 
    ll *disc = new ll[n]; 
    ll *low = new ll[n]; 
    ll *parent = new ll[n]; 
    //bool *ap = new bool[n]; // To store is an articulation point
    fo(i,0,n){
		visited[i]=false;
		parent[i]=-1;
		//ap[i]=false;
	}
	for (i = 0; i < n; i++) 
        if (!visited[i]){ 
			curr_time=0;
            BridgeUtil(edges,i, visited, disc, low, parent); 
		}
    //for (i = 0; i < n; i++) 
        //if (ap[i]) 
            //cout << i << " "; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,e,i;
	cin>>n>>e;
	vector<ll>* edges = new vector<ll>[n];
	fo(i,0,e){
		ll u,v;
		cin>>u>>v;
		//considering zero based vertices
		edges[u].pbb(v);
		edges[v].pbb(u);
	}
	findBridges(edges,n);
	return 0;
}
