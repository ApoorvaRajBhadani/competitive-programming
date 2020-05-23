#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool graph[19][19];
ll parent[19];
unordered_map<ll,queue<ll>> setelements;
ll currsetid[19];
ll reqsetid[19];
ll wrongcount=0;
set<ll> mycurrcost;
vector<ll> sequence;
ll topparent(ll child){
	while(parent[child]!=-1){
		child = parent[child];
	}
	return child;
}
void uniteparent(ll s,ll d){
	ll stp,dtp;
	stp = topparent(s);
	dtp = topparent(d);
	if(stp!=dtp){
		parent[dtp] = stp;
	}
}
ll mamlaSaltao(ll& wrongcount,ll mysetid,ll elementvisit,ll& etbp){
	ll myreqsetid = reqsetid[elementvisit];
	//cout<<"req set id of"<<elementvisit<<" is " <<myreqsetid<<endl;
	if(myreqsetid == mysetid){
		setelements[myreqsetid].push(elementvisit);
		currsetid[elementvisit] = myreqsetid;
		wrongcount--;
		etbp = elementvisit;
		mycurrcost.insert(etbp);sequence.push_back(myreqsetid);
		return 0;
	}
	ll mycurrsetid = currsetid[elementvisit];
	if(myreqsetid == mycurrsetid){
		setelements[myreqsetid].push(elementvisit);
		elementvisit = setelements[myreqsetid].front();setelements[myreqsetid].pop();
		return mamlaSaltao(wrongcount,mysetid,elementvisit,etbp);
	}
	setelements[myreqsetid].push(elementvisit);
	currsetid[elementvisit] = myreqsetid;mycurrcost.insert(elementvisit);
	sequence.push_back(myreqsetid);
	wrongcount--;
	elementvisit = setelements[myreqsetid].front();setelements[myreqsetid].pop();
	return 1+mamlaSaltao(wrongcount,mysetid,elementvisit,etbp);
}
void solve(){
	//cout<<"hi"<<endl;
	memset(graph,false,sizeof(graph));
	for(ll i=0;i<=18;i++) {
		parent[i]=-1;
		currsetid[i]=0;
		reqsetid[i]=0;
	}
	setelements.clear();
	wrongcount=0;
	ll n,m,i,ans=0;
	cin>>n>>m;
	ll arr[n+1];
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(i=1;i<=m;i++){
		ll x,y;
		cin>>x>>y;
		graph[x][y]=graph[y][x]=true;
		if(topparent(x)!=topparent(y)){
			//join them
			uniteparent(x,y);
		}
	}
	
	for(i=1;i<=n;i++){
		ll setid = topparent(i);
		setelements[setid].push(arr[i]);
		currsetid[arr[i]]=setid;
		ll myreqsetid = topparent(arr[i]);
		reqsetid[arr[i]] = myreqsetid;
		if(myreqsetid!=setid) wrongcount++;
	}
	
	//while(wrongcount>0){
		//cout<<wrongcount<<endl;
		for(auto it= setelements.begin();it!=setelements.end();it++){
			ll mysetid = it->first;
			queue<ll>& mysetelements = it->second;
			for(i=0;i<mysetelements.size();i++){
				ll elementvisit = mysetelements.front();mysetelements.pop();
				//cout<<"element visit "<<elementvisit<<endl;
				if(reqsetid[elementvisit]==currsetid[elementvisit]){
					mysetelements.push(elementvisit);
				}else{
					mycurrcost.clear();
					sequence.clear();
					ll etbp;
					sequence.push_back(mysetid);
					ll currcost = mamlaSaltao(wrongcount,mysetid,elementvisit,etbp);
					currsetid[etbp] = mysetid;
					wrongcount--;
					//for(auto itt=mycurrcost.begin();itt!=mycurrcost.end();itt++) cout<<*itt<<" ";
					//cout<<endl;
					currcost=0;
					map<ll,ll> sequencedepth;
					ll depth = 0;
					for(ll jj=0;jj<sequence.size();jj++) {
						ll seqval = sequence[jj];
						//cout<<seqval<<" ";
						if(sequencedepth[seqval]==0){
							depth++;
							sequencedepth[seqval] = depth;
						}else{
							currcost+= depth-sequencedepth[seqval];
							for(ll jjj=jj-1;jjj>=0;jjj--){
								if(sequence[jjj]==seqval) break;
								sequencedepth[sequence[jjj]] = 0;
							}
							depth=sequencedepth[seqval];
						}
					}
					//cout<<endl;
					//cout<<"curr cost"<<currcost<<endl;
					ans+=currcost;
				}
			}
		}
	//}
	cout<<ans<<endl;
	//cout<<"Ans is "<<ans<<endl<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) {
		
		solve();
	}
	return 0;
}
