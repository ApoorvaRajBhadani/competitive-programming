#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll n;
ll dc[4000],hc[4000],sc[4000],present[4000];
queue<ll> margaya;
void rulaoo(){
	while(!margaya.empty()){
		ll yehmara = margaya.front();
		//cout<<yehmara<<endl;
		margaya.pop();
		if(!present[yehmara]) continue;
		present[yehmara]=0;
		ll d = hc[yehmara];
		for(ll i = yehmara+1;i<n;i++){
			if(!present[i]) continue;
			sc[i]-=d;
			//cout<<i+1<<" red from "<<sc[i]+d<<" to "<<sc[i]<<endl;
			if(sc[i]<0) {
				margaya.push(i);
				//cout<<i+1<<" made unpresent by "<<yehmara+1<<endl;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll i,j;
	vector<ll> bach;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>dc[i]>>hc[i]>>sc[i];
		present[i]=1;
	}
	for(ll docat = 0;docat<n;docat++){
		if(!present[docat]) {
			continue;
		}

		bach.push_back(docat+1);
		ll v = dc[docat];
		for(i=docat+1;i<n && v>0;i++){
			if(!present[i]) continue;
			//cout<<i+1<<" red from "<<sc[i];
			sc[i]-=v;
			//cout<<" to "<<sc[i]<<endl;
			if(sc[i]<0) margaya.push(i);
			v--;
		}
		rulaoo();
	}
	cout<<bach.size()<<endl;
	for(auto it=bach.begin();it!=bach.end();it++) cout<<*it<<" ";
	return 0;
}





















