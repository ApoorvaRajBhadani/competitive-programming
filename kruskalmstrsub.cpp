#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
struct Edge{
	ll s,d,w;
};
bool compareWeight(Edge a,Edge b){
	if( a.w<b.w){
		return true;
	}
	return false;
}
ll topParent(ll* parent,ll child){
	while(parent[child]!=-1){
		child = parent[child];
	}
	return child;
}
void uniteparent(ll* parent,ll s,ll d){
	ll stp,dtp;
	stp = topParent(parent,s);
	dtp = topParent(parent,d);
	if(stp!=dtp){
		parent[dtp] = stp;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,m,i;
	cin>>n>>m;
	vector<Edge> vec;
	for(i=0;i<m;i++){
		Edge ed = {0,0,0};
		cin>>ed.s>>ed.d>>ed.w;
		ed.s--;
		ed.d--;
		vec.push_back(ed);
	}
	sort(vec.begin(),vec.end(),compareWeight);
	ll* parent = new ll[n];
	for(i=0;i<n;i++) parent[i] = -1;
	ll start=0,end,ans=0,count=0;
	while(start<m && count<(n-1)){
		ll wgt=vec[start].w,i=start;
		while(vec[i].w == wgt && i<m){
			i++;
		}
		end = i;
		ll mnwgt = INT_MAX,sss,ddd;
		bool mila=false;
		for(ll j = start;j<end;j++){
				ll stp = topParent(parent,vec[j].s);
				ll dtp = topParent(parent,vec[j].d);
				if(stp != dtp){
					sss = vec[j].s;
					ddd = vec[j].d;
					mila = true;
				}
		}
		if(mila){
			uniteparent(parent,sss,ddd);
			ans+=vec[start].w;
		}
		mila = false;
		start = end;
	}
	cout<<ans;
	return 0;
}
