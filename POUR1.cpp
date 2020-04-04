#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
struct State{
	ll ah,bh,dep;
};
ll a,b,c;
ll bfs(queue<State> qu){
	map<pair<ll,ll>,bool> mp;
	while(!qu.empty()){
		State visit = qu.front();
		qu.pop();
		if(mp[make_pair(visit.ah,visit.bh)]) continue;
		mp[make_pair(visit.ah,visit.bh)]=true;
		//cout<<visit.ah<<" "<<visit.bh<<" "<<visit.dep<<endl;
		if(visit.ah==c||visit.bh==c) return visit.dep;
		if(visit.ah==0){
			State nst = {a,visit.bh,visit.dep+1};
			qu.push(nst);
		}
		//else if(visit.bh<b){
			//State nst = {visit.ah,b,visit.dep+1};
			//qu.push(nst);
		//}
		//if(visit.ah!=0){
			//State nst = {0,visit.bh,visit.dep+1};
			//qu.push(nst);
		//}
		else if(visit.bh==b){
			State nst = {visit.ah,0,visit.dep+1};
			qu.push(nst);
		}
		//transfer a to b
			else if(visit.ah>(b-visit.bh)){
				State nst = {visit.ah-(b-visit.bh),b,visit.dep+1};
				qu.push(nst);
			}else{
				State nst = {0,visit.bh+visit.ah,visit.dep+1};
				qu.push(nst);
			}
			//if(visit.bh>(a-visit.ah)){
				//State nst ={a,visit.bh-(a-visit.ah),visit.dep+1};
				//qu.push(nst);
			//}else{
				//State nst = {visit.ah+visit.bh,0,visit.dep+1};
				//qu.push(nst);
			//}
	}
	
}
ll bfs2(queue<State> qu){
	map<pair<ll,ll>,bool> mp;
	while(!qu.empty()){
		State visit = qu.front();
		qu.pop();
		if(mp[make_pair(visit.ah,visit.bh)]) continue;
		mp[make_pair(visit.ah,visit.bh)]=true;
		//cout<<visit.ah<<" "<<visit.bh<<" "<<visit.dep<<endl;
		if(visit.ah==c||visit.bh==c) return visit.dep;
		//if(visit.ah<a){
			//State nst = {a,visit.bh,visit.dep+1};
			//qu.push(nst);
		//}
		if(visit.bh==0){
			State nst = {visit.ah,b,visit.dep+1};
			qu.push(nst);
		}
		if(visit.ah==a){
			State nst = {0,visit.bh,visit.dep+1};
			qu.push(nst);
		}
		//if(visit.bh!=0){
			//State nst = {visit.ah,0,visit.dep+1};
			//qu.push(nst);
		//}
		//transfer a to b
			//if(visit.ah>(b-visit.bh)){
				//State nst = {visit.ah-(b-visit.bh),b,visit.dep+1};
				//qu.push(nst);
			//}else{
				//State nst = {0,visit.bh+visit.ah,visit.dep+1};
				//qu.push(nst);
			//}
			else if(visit.bh>(a-visit.ah)){
				State nst ={a,visit.bh-(a-visit.ah),visit.dep+1};
				qu.push(nst);
			}else{
				State nst = {visit.ah+visit.bh,0,visit.dep+1};
				qu.push(nst);
			}
	}
	
}
void solve(){
	cin>>a>>b>>c;
	if(c>max(a,b) || c%__gcd(a,b)!=0){
		cout<<-1<<endl;
		return;
	}
	queue<State> qu;
	State st={0,0,0};
	qu.push(st);
	cout<<min(bfs(qu),bfs2(qu))<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
