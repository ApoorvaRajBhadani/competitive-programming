#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
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
const ll LG = 20;
const ll N = 2e5;
ll a[N], lvl[N], P[N][LG];
//ONE BASED INDEX OF NODES
void dfs(ll u, ll par,vi* graph){
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
	for(auto v:graph[u]){
		if (v == par) continue;
		dfs(v, u,graph);
	}
}
void lca_compute(ll n,vi* graph){
    ll i,j;
    fo(i,0,LG) fo(j,0,n+1) P[j][i] = -1;
	lvl[0] = -1;
    dfs(1, 0,graph);
    fo(i,1,LG){
        fo(j, 1, n+1){
            if (P[j][i-1] != -1) P[j][i] = P[P[j][i-1]][i-1];
        }
	}
}
ll lca(ll u, ll v){
    ll i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);
    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;
    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }
    if (u == v) return u;

    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }
    return P[u][0];
}
//Get the ancestor of node "u"
//which is "dis" distance above.
ll getAncestor(ll u, ll dis){
    dis = lvl[u] - dis;
    ll i, lg = 0;
    for(; (1<<lg) <= lvl[u]; lg++); lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= dis)
            u = P[u][i];
    }

    return u;
}
//returns the distance between
//two nodes "u" and "v".
ll distance(ll u, ll v){
    if (lvl[u] < lvl[v]) swap(u, v);
    ll w = lca(u, v);
    return lvl[u] + lvl[v] - 2*lvl[w];
}
int main(){
	ll i, n, j;
	cin >> n;
    vi* graph = new vi[n+5];
	fo(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        //one based one index
        graph[u].pbb(v);
        graph[v].pbb(u);
	}
    lca_compute(n,graph);
}
