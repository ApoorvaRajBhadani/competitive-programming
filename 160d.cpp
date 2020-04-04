#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
struct Edge{
	ll s,d,w,idx,confrom,conto;
	string ans="";
};
bool compareWeight(Edge a,Edge b){
	return a.w<b.w;
}
bool compareIdx(Edge a,Edge b){
	return a.idx<b.idx;
}
ll topParent(ll* parent,ll child){
	while(parent[child]!=-1){
		child = parent[child];
	}
	return child;
}
ll uniteparent(ll* parent,ll s,ll d){
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
		Edge ed = {0,0,0,0,0,0,""};
		cin>>ed.s>>ed.d>>ed.w;
		ed.idx = i;
		vec.push_back(ed);
	}
	sort(vec.begin(),vec.end(),compareWeight);
	ll* parent = new ll[n];
	for(i=0;i<n;i++) parent[i] = -1;
	ll start=0,end;
	while(start<m){
		ll wgt=vec[start].w,i=start;
		while(vec[i].w == wgt && i<m){
			i++;
		}
		end = i;
		if(end-start == 1){
			if(topParent(parent,vec[start].s) != topParent(parent,vec[start].d)){
				vec[start].ans = "any";
				uniteparent(parent,vec[start].s,vec[start].d);
			}else{
				vec[start].ans = "none";
			}
		}
		else{
			map<pair<ll,ll>,ll> mp;
			for(ll j = start;j<end;j++){
				ll stp = topParent(parent,vec[j].s);
				ll dtp = topParent(parent,vec[j].d);
				if(stp == dtp){
					vec[j].ans = "none";
				}else{
					mp[make_pair(min(stp,dtp),max(stp,dtp))]++;
				}
			}
			for(ll j=start;j<end;j++){
				ll stp = topParent(parent,vec[j].s);
				ll dtp = topParent(parent,vec[j].d);
				if(stp!=dtp){
					if(mp[make_pair(min(stp,dtp),max(stp,dtp))] >1){
						vec[j].ans = "at least one";
					}else{
						vec[j].ans = "any";
					}
				}
			}
			for(auto it=mp.begin();it!=mp.end();it++){
				uniteparent(parent,(*it).first.first,(*it).first.second);
			}
		}
		start = end;
	}
	sort(vec.begin(),vec.end(),compareIdx);
	for(auto it = vec.begin();it!=vec.end();it++){
		cout<<(*it).ans<<endl;
	}
	return 0;
}
