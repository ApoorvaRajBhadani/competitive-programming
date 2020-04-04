#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool dfs(vector<ll>* edges,bool* visited,ll n,int startcolor,int* color,ll start){
	visited[start] = true;
	color[start] = startcolor;
	ll i;
	for(i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			bool check = dfs(edges,visited,n,startcolor^1,color,adjv);
			if(!check) return false;
		}
		if(color[adjv]!=(startcolor^1)) return false;
	}
	return true;
}
bool bipartite(vector<ll>* edges, ll n) {
	int* color = new int[n];
	bool* visited = new bool[n];
	ll i;
	for(i=0;i<n;i++) {
		color[i]=2;
		visited[i] = false;
	}
	//2 means not yet colored
	for(i=0;i<n;i++){
		if(!visited[i]){
			bool check = dfs(edges,visited,n,0,color,i);
			if(!check) return false;
		}
	}
	return true;
}
/*
bool bipartite(vector<ll>* edges, ll n) {
	if (n == 0) {
		return true;
	}
	unordered_set<ll> sets[2];
	vector<ll> pending;
	sets[0].insert(0);
	pending.push_back(0);
	while (pending.size() > 0) {
		ll current = pending.back();
		pending.pop_back();
		ll currentSet = sets[0].count(current) > 0 ? 0 : 1;
		for (ll i = 0; i < edges[current].size(); i++) {
			ll neighbor = edges[current][i];
			if (sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0) {
				sets[1 - currentSet].insert(neighbor);
				pending.push_back(neighbor);
			} else if (sets[currentSet].count(neighbor) > 0) {
				return false;
			}
		}
	}
	return true;
}
*/
ll topParent(ll child,ll* parent){
    while(parent[child]!=child){
        child = parent[child];
    }
    return child;
}
void solve(){
    bool ans=true;
    ll n,q;
    cin>>n>>q;
    vector<pair<ll,ll>> zeros,ones;
    map<ll,map<ll,ll>> inputMap;
    for(ll i=0;i<q;i++){
        ll x,y,val;
        cin>>x>>y>>val;
        x--;y--;
        if(x==y) {
            if(val==1){
            ans = false;
            }
        }
         inputMap[x][y] = val+1;
        if(inputMap[y][x]!=0 && inputMap[x][y]!=inputMap[y][x]) {
			ans = false;
		}
       
        if(val) ones.push_back(make_pair(x,y));
        else zeros.push_back(make_pair(x,y));
    }
    if(!ans) {cout<<"no"<<endl;return;}
    ll* parent = new ll[n];
    fo(i,0,n-1) parent[i]=i;
    for(auto it=zeros.begin();it!=zeros.end();it++){
        ll s = it->first,d=it->second;
        parent[d] = parent[s];
    }
    ll* topparent = new ll[n];
    for(ll i=0;i<n;i++){
        topparent[i] = -1*topParent(i,parent);
    }
    set<ll> distNodes;
    map<ll,ll> newnodename;
    ll v=0;
    for(ll i=0;i<n;i++){
        auto pos = distNodes.find(topparent[i]);
        if(pos==distNodes.end()){
            newnodename[topparent[i]] = v;
            topparent[i] = v;
            v++;
        }else{
            topparent[i] = newnodename[topparent[i]];
        }
    }
    vector<ll>* edges = new vector<ll>[v];
    for(auto it=ones.begin();it!=ones.end();it++){
        ll v1 = topparent[it->first],v2= topparent[it->second];
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    ans = bipartite(edges,v);
    if(ans) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}
