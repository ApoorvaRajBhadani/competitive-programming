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
struct Subset{ 
    ll parent; 
    ll rank; 
};
ll findSet(Subset subsets[], ll i) {
    if (subsets[i].parent != i) 
        subsets[i].parent = findSet(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 
ll setmax[200005];
void uniteSet(Subset subsets[], ll x, ll y) { 
    ll xroot = findSet(subsets, x); 
    ll yroot = findSet(subsets, y); 
    ll xmax = setmax[xroot];
    ll ymax = setmax[yroot];
    setmax[xroot]=setmax[yroot]=max(xmax,ymax);
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
    else{ 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
}
void solve(ll caseno){
	ll i,j,n,m,u,v;
    cin>>n>>m;

    //makeSet
	Subset *subsets = (Subset*)malloc(n*sizeof(Subset)); 
    for ( i = 0; i < n; ++i) { 
        subsets[i].parent = i; 
        subsets[i].rank = 0; 
        setmax[i]=i;
    } 


    fo(i,0,m){
        cin>>u>>v;
        u--;v--;
        ll setofu=findSet(subsets,u);
        ll setofv=findSet(subsets,v);
        setmax[setofu] = max(setmax[setofu],u);
        setmax[setofv] = max(setmax[setofv],v);
        if(findSet(subsets,u)!=findSet(subsets,v)){
			uniteSet(subsets,u,v);
		}
    }

    ll ans=0;
    i=0;
    while(i<n){
        ll curset = findSet(subsets,i);
        ll cursetmax = setmax[curset];
        for(i=i+1;i<=cursetmax;i++){
            if(findSet(subsets,i)!=curset){
                ans++;
                uniteSet(subsets,curset,i);
                curset = findSet(subsets,i);
                cursetmax = max(cursetmax,setmax[curset]);
            }
        }
    }
    cout<<ans<<endl;
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
