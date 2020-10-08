#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
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
void tarjansdfs(ll u,vector<vi> &graph,vi &disc,vi &low,vector<bool> &instk,stack<ll> &mystk){
    static ll timer = 0;
    low[u]=disc[u]=timer++;
    mystk.push(u);
    instk[u]=true;

    for(auto v:graph[u]){
        if(disc[v]==-1){
            //not visited
            tarjansdfs(v,graph,disc,low,instk,mystk);
            low[u] = min(low[u],low[v]);
        }else if(instk[v]){
            //visited,back-edge
            low[u] = min(low[u],disc[v]);
        }else{
            //visited,cross-edge
            //not to be processed
        }
    }
    if(low[u]==disc[u]){
        //head of SCC
        cout<<"SCC is: ";
        while(mystk.top()!=u){
            ll w = mystk.top();mystk.pop();
            instk[w]=false;
            cout<<w<<' ';
        }
        cout<<u<<endl;
        mystk.pop();
        instk[u]=false;
    }
}
void findscctarjan(ll n,vector<vi> &graph){
    vi disc(n,-1),low(n,-1);
    vector<bool> instk(n,false);
    stack<ll> mystk;
    ll i;
    fo(i,0,n)
        if(disc[i]==-1)
            tarjansdfs(0,graph,disc,low,instk,mystk);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    ll n,m,i;
    cin>>n>>m;
    //0 based numbering of nodes in graph
    vector<vi> graph(n);
    fo(i,0,m){
        ll u,v;
        cin>>u>>v;
        //edge from u -> v
        graph[u].pbb(v);
    }
    findscctarjan(n,graph);
	return 0;
}