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
int graph[25][25];
vi locs[25];
bool exist[25];
void dfs(int u,vector<bool>& vis,stack<int>& stk){
    vis[u]=true;
    for(int i=0;i<20;i++){
        if(graph[u][i] && !vis[i]){
            dfs(i,vis,stk);
        }
    }
    stk.push(u);
}
vi toposort(){
    vi ans;
    vector<bool> vis(20,false);
    stack<int> stk;
    for(int i=0;i<20;i++){
        if(!vis[i] && exist[i]){
            dfs(i,vis,stk);
        }
    }
    while(!stk.empty()){
        ans.pbb(stk.top());
        stk.pop();
    }
    return ans;
}
void solve(ll caseno){
	ll i,j,n,ans=0;
    string a,b;
    cin>>n>>a>>b;
    mset(graph,0);
    mset(exist,0);
    fo(i,0,n){
        exist[a[i]-'a']=exist[b[i]-'a']=true;
        if(a[i]>b[i]){
            cout<<-1<<endl;
            return;
        }else if(b[i]>a[i]){
            graph[a[i]-'a'][b[i]-'a']=1;
        }
        locs[a[i]-'a'].pbb(i);
    }
    vi tso = toposort();
    for(auto o:tso) cout<<(char)(o+'a')<<' ';cout<<endl;
    for(i=0;i<tso.size()-1;i++){
        int u=tso[i],v=tso[i+1];
        int conv=0;
        for(auto idx:locs[u]){
            if(a[idx]==b[idx]) continue;
            locs[v].pbb(idx);
            conv=1;
        }
        ans+=conv;
    }
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
