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
#define INF 1e9
ll bfs(ll s, ll t, vector<ll>& parent,vvi &adj,vvi &capacity) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t,ll n,vvi &adj,vvi &capacity) {
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;

    while ((new_flow = bfs(s, t, parent,adj,capacity))) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    ll n,m,i;
    cin>>n>>m;
    vvi graph(n);
    vvi capacity(n,vector<ll>(n,0));
    fo(i,0,m){
        ll u,v,c;
        cin>>u>>v>>c;
        graph[u].pbb(v);
        capacity[u][v]=c;
    }
    cout<<maxflow(n-2,n-1,n,graph,capacity)<<endl;
	return 0;
}