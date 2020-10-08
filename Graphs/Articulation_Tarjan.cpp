#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define setbits(x) __builtin_popcountll(x)
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
void findapsutil(ll u,vector<vi> &graph,vi &disc,vi &low,vi &par,vb &isap){
    static ll timer = 0;
    disc[u]=low[u]=timer++;
    ll childs=0;
    for(auto v:graph[u]){
        if(disc[v]==-1){
            childs++;
            par[v]=u;
            findapsutil(v,graph,disc,low,par,isap);
            low[u] = min(low[u],low[v]);

            if(par[u]==-1 && childs>1){
                //Case 1 : u is root node of DFS tree and unique subgraphs of u is more than 1
                isap[u]=true;
            }
            if(par[u]!=-1 && low[v]>=disc[u]){
                //Case 2 : subgraph is not connected to ancestor of u
                isap[u]=true;
            }
        }else if(v!=par[u]){
            //v is vistied and v is not parent of u
            //back-edge
            low[u] = min(low[u],disc[v]);
        }
    }
}
void findaps(ll n,vector<vi> &graph){
    //O(n+m)
    vi disc(n,-1),low(n,-1),par(n,-1);
    vb isap(n,false);
    ll i;
    fo(i,0,n){
        if(disc[i]==-1) 
            findapsutil(i,graph,disc,low,par,isap);
    }
    fo(i,0,n){
        if(isap[i]) cout<<i<<' ';
    }
    cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    ll n,m,i;
    cin>>n>>m;
    vector<vi> graph(n);
    fo(i,0,m){
        ll u,v;
        cin>>u>>v;
        //0 based numbering of nodes edges are bidirectional/undirected
        graph[u].pbb(v);
        graph[v].pbb(u);
    }
    findaps(n,graph);
	return 0;
}