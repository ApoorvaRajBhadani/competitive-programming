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
ll topic[500005];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	if(a.ff==b.ff) return a.ss<b.ss;
	return a.ff<b.ff;
}
void solve(){
	ll i,j,n,m;
	cin>>n>>m;
	vector<ll>* edges = new vector<ll>[n];
	fo(i,0,m){
		ll u,v;
		cin>>u>>v;
		u--;v--;
		edges[u].pbb(v);
		edges[v].pbb(u);
	}
	vector<pair<ll,ll>> vec;
	fo(i,0,n){
		cin>>topic[i];
		vec.pbb(mpp(topic[i],i));
	}
	fo(i,0,n){
		set<ll> st;
		for(auto v:edges[i]){
			if(topic[i]==topic[v]){
				cout<<-1<<endl;
				return;
			}else if(topic[i]>topic[v]){
				st.insert(topic[v]);
			}
		}
		if(st.size()!=topic[i]-1){
			cout<<-1<<endl;
				return;
		}
	}
	sort(all(vec),cmp);
	for(auto nn:vec) cout<<nn.ss+1<<" ";
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
