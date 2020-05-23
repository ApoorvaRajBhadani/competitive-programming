#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
#define MAXN   1000005
ll spf[MAXN];
map<ll,vector<ll>> dfsresult;
map<ll,map<ll,ll>> pfacs,pfacssum;
map<ll,ll> nodeval;
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
    for (ll i=3; i*i<MAXN; i++) 
    {
        if (spf[i] == i) 
        { 
            for (ll j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}
void getFactorization(ll x,ll idx) 
{  
    while (x != 1) 
    { 
        pfacs[idx][spf[x]]++;
        x = x / spf[x]; 
    } 
}
void dfs(vector<ll>* edges,bool* visited,ll start,vector<ll>& dfsseq,map<ll,ll>& pfacsuntilnow){
	visited[start]=true;
	dfsseq.push_back(start);
	//cout<<"now at "<<start+1<<endl;
	for(auto it = pfacs[start].begin();it!=pfacs[start].end();it++){
		pfacsuntilnow[it->first]+=it->second;
		//cout<<it->first<<" "<<it->second<<endl;
	}
	for(auto it = pfacsuntilnow.begin();it!=pfacsuntilnow.end();it++){
		pfacssum[start][it->first]=it->second;
	}
	dfsresult[start]= dfsseq;
	for(ll i=0;i<edges[start].size();i++){
		ll adjv = edges[start][i];
		if(!visited[adjv]){
			dfs(edges,visited,adjv,dfsseq,pfacsuntilnow);
		}
	}
	dfsseq.erase(dfsseq.end()-1);
}
void solve(){
	dfsresult.clear();
	pfacs.clear();
	nodeval.clear();
	ll n,i,q,j;
	cin>>n;
	vector<ll>* edges= new vector<ll>[n];
	for(i=0;i<n-1;i++){
		ll s,d;
		cin>>s>>d;
		s--;d--;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	for(i=0;i<n;i++){
		ll a;
		cin>>a;
		getFactorization(a,i);
		nodeval[i]=a;
	}
	//for(i=0;i<n;i++){
		//cout<<"prime factorisation of A"<<i+1<<" ";
		//for(auto it=pfacs[i].begin();it!=pfacs[i].end();it++){
			//cout<<it->first<<"^"<<it->second<<" ";
		//}
		//cout<<endl;
	//}
	bool* visited = new bool[n]();
	vector<ll> dfsseq;
	map<ll,ll> pfacsuntilnow;
	dfs(edges,visited,0,dfsseq,pfacsuntilnow);
	//for(i=0;i<n;i++){
		//cout<<"dfs of "<<i+1<<" : ";
		//for(auto it=dfsresult[i].begin();it!=dfsresult[i].end();it++){
			//cout<<*it +1<<" ";
		//}
		//cout<<endl;
	//}
	//for(i=0;i<n;i++){
		//cout<<"prime factorisation of root to node"<<i+1<<" ";
		//for(auto it=pfacssum[i].begin();it!=pfacssum[i].end();it++){
			//cout<<it->first<<"^"<<it->second<<" ";
		//}
		//cout<<endl;
	//}
	cin>>q;
	for(i=0;i<q;i++){
		ll u,v,mn;
		cin>>u>>v;
		u--;v--;
		vector<ll>& uvec = dfsresult[u];
		vector<ll>& vvec = dfsresult[v];
		mn = min(uvec.size(),vvec.size());
		//binary search to find LCA
		ll left = 0,right = mn-1;
		ll mid = (left+right)/2;
		while(true){
			if(left==right) break;
			else if(uvec[mid]!=vvec[mid]){
				right = mid-1;
			}else{
				if(mid==mn-1){
					break;
				}else if(uvec[mid+1]!=vvec[mid+1]){
					break;
				}else{
					left=mid+1;
				}
			}
			mid = (left+right)/2;
		}
		//cout<<"subroot="<<uvec[mid]<<endl;
		map<ll,ll> mypfacs;
		for(auto it = pfacs[vvec[mid]].begin();it!=pfacs[vvec[mid]].end();it++){
			mypfacs[it->first]+=it->second;
		}
		for(auto it = pfacssum[u].begin();it!=pfacssum[u].end();it++){
			mypfacs[it->first]+=it->second;
		}
		for(auto it = pfacssum[v].begin();it!=pfacssum[v].end();it++){
			mypfacs[it->first]+=it->second;
		}
		for(auto it = pfacssum[vvec[mid]].begin();it!=pfacssum[vvec[mid]].end();it++){
			mypfacs[it->first]-=2* it->second;
		}
		//for(j=mid+1;j<uvec.size();j++){
			//for(auto it = pfacs[uvec[j]].begin();it!=pfacs[uvec[j]].end();it++){
				//mypfacs[it->first]+=it->second;
			//}
		//}
		//for(j=mid+1;j<vvec.size();j++){
			//for(auto it = pfacs[vvec[j]].begin();it!=pfacs[vvec[j]].end();it++){
				//mypfacs[it->first]+=it->second;
			//}
		//}
		ll ans=1;
		for(auto it=mypfacs.begin();it!=mypfacs.end();it++){
			ans=((ans%MOD)*((it->second+1)%MOD))%MOD;
		}
		cout<<ans<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	sieve();
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
