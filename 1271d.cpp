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
ll n,a[5005],b[5005],c[5005];
ll mxpapa[5005];
vi gotochild[5005];
ll answer(ll idx,ll k,vi* graph){
    if(idx==n) return 0;
    if(k<a[idx]) return INT_MIN;
    k+=b[idx];
    ll ans=answer(idx+1,k,graph);
    for(auto ch:gotochild[idx]){
        ans=max(ans,c[ch]+answer(idx+1,k-1,graph));
    }
    return ans;
}
void solve(ll caseno){
	ll i,j,m,k,total=0;
    bool anspos=true;
    cin>>n>>m>>k;
    fo(i,0,n){
        cin>>a[i]>>b[i]>>c[i];
    }
    vi* graph = new vi[n];
    vi* grapht= new vi[n];
    fo(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        graph[u].pbb(v);
        graph[v].pbb(u);
    }
    fo(i,0,n) {
        graph[i].pbb(i);
        grapht[i].pbb(i);
    }
    fo(i,0,n){
        for(auto v:grapht[i]){
            mxpapa[i]=max(mxpapa[i],v);
        }
        gotochild[mxpapa[i]].pbb(i);
    }
    total = answer(0,k,graph);
    if(total>=0) cout<<total<<endl;
    else cout<<-1<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
