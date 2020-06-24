#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
//DSU by rank and path compression
//https://codeforces.com/problemset/problem/1133/F1
struct Subset{ 
    ll parent; 
    ll rank; 
};
int findSet(Subset subsets[], ll i) {
    if (subsets[i].parent != i) 
        subsets[i].parent = findSet(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 
void uniteSet(Subset subsets[], ll x, ll y) { 
    int xroot = findSet(subsets, x); 
    int yroot = findSet(subsets, y); 
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
    else{ 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
}
void solve(){
	ll i,j,n,m;
	cin>>n>>m;
	vector<ll>* edges = new vector<ll>[n];
	fo(i,1,m){//O(m)
		ll u,v;
		cin>>u>>v;
		u--;v--;
		edges[u].pbb(v);
		edges[v].pbb(u);
	}
	ll vmxe = -1,mxe=0;
	fo(i,0,n-1){//O(n)
		if(edges[i].size()>=mxe) {
			mxe = edges[i].size();
			vmxe = i;
		}
	}
	//cout<<vmxe+1<<endl;
	ll count = 0;
	
	//makeSet
	Subset *subsets = (Subset*)malloc(n*sizeof(Subset)); 
    for ( i = 0; i < n; ++i) { 
        subsets[i].parent = i; 
        subsets[i].rank = 0; 
    } 
    
    
	vector<ll> ans;
		for(i=0;i<=mxe-1&&count<n-1;i++){
			ll adjv = edges[vmxe][i];
			if(findSet(subsets,adjv)!=findSet(subsets,vmxe)){
				uniteSet(subsets,adjv,vmxe);
				ans.pbb(adjv);
				ans.pbb(vmxe);
				//cout<<adjv<<" "<<vmxe<<endl;
				count++;
			}
		}
		for(i=0;i<=n-1&&count<n-1;i++){
			if(i==vmxe) continue;
			for(j=0;j<=edges[i].size()-1&&count<n-1;j++){
				ll adjv = edges[i][j];
				if(findSet(subsets,i)!=findSet(subsets,adjv)){
					uniteSet(subsets,i,adjv);
					ans.pbb(i);
					ans.pbb(adjv);
					//cout<<i<<" "<<adjv<<endl;
					count++;
				}
			}
		}
	fo(i,0,2*(n-1)-1){
		cout<<ans[i++]+1<<" "<<ans[i]+1<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
