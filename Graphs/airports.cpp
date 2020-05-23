#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
struct Edge{
	ll s,d,c;
};
bool compare(Edge a,Edge b){
	return a.c<b.c;
}
ll topparent(ll* parent,ll child){
	while(parent[child]!=-1){
		child = parent[child];
	}
	return child;
}
ll uniteparent(ll* parent,ll s,ll d){
	ll stp,dtp;
	stp = topparent(parent,s);
	dtp = topparent(parent,d);
	if(stp!=dtp){
		parent[dtp] = stp;
	}
}
void solve(int caseno){
	ll n,e,ac,i,cost,airports;
	cin>>n>>e>>ac;
	vector<Edge> edges;
	for(i=0;i<e;i++){
		ll s,d,c;
		cin>>s>>d>>c;
		s--;d--;
		if(c<ac){
			edges.push_back({s,d,c});
		}
	}
	sort(edges.begin(),edges.end(),compare);
	airports = n;
	cost = n*ac;
	ll* parent = new ll[n];
	for(i=0;i<n;i++) parent[i] = -1;
	ll noe = edges.size();
	//cout<<noe<<endl;
	for(i=0;i<noe;i++){
		Edge ed = edges[i];
		//cout<<"now edge is "<<ed.s<<" "<<ed.d<<endl;
		//cout<<"topparent of "<<ed.s<<" is "<<topparent(parent,ed.s)<<endl;
		//cout<<"topparent of "<<ed.d<<" is "<<topparent(parent,ed.d)<<endl;
		
		if(topparent(parent,ed.s)!=topparent(parent,ed.d)){
			//join them
			uniteparent(parent,ed.s,ed.d);
			cost-=ac;
			airports--;
			cost+=ed.c;
		}
	}
	cout<<"Case "<<caseno<<": "<<cost<<" "<<airports<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	fo(i,1,t) solve(i);
	return 0;
}
