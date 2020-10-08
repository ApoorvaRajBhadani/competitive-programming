#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
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

void findBridgesUtil(ll u,vvi &graph,vi &disc,vi &low,vi &par){
    static ll timer = 0;
    disc[u]=low[u]=timer++;
    for(auto v:graph[u]){
        if(disc[v]==-1){ //v is not visited
            par[v]=u;
            findBridgesUtil(v,graph,disc,low,par);
            low[u] = min(low[u],low[v]);

            if(low[v]>disc[u])
                cout<<u<<"---"<<v<<endl;
        }else if(par[u]!=v) //Back-edge and ignoring child to parent edge
            low[u] = min(low[u],disc[v]);
    }
}
void findBridges(vvi &graph,ll n){ //Tarjan's Algorithm for Bridges
    vi disc(n,-1),low(n,-1),par(n,-1);
    ll i;
    fo(i,0,n)
        if(disc[i]==-1) 
            findBridgesUtil(i,graph,disc,low,par);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    ll n,m,i;
    cin>>n>>m;
    vvi graph(n);
    fo(i,0,m){
        ll u,v;
        cin>>u>>v;//nodes numbered 0 to n-1
        graph[u].pbb(v);
        graph[v].pbb(u);
    }
    findBridges(graph,n);
	return 0;
}