#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll idx[200001];
void solve(){
	ll i,j,n,kk,wrong=0,m=0;
	cin>>n>>kk;
	ll arr[n+1];arr[0]=0;
	memset(idx,0,sizeof(idx));
	for(i=1;i<=n;i++) {
		cin>>arr[i];
		idx[arr[i]]=i;
		if(arr[i]!=i) wrong++;
	}
	vector<ll> ans;
	for(i=1;i<=n;i++){
		//if(wrong==2){
			//cout<<-1<<endl;
			//return;
		//}
		//else if(wrong==0){
			//break;
		//}
		if(arr[i]==i) continue;
		//tripple swapping
		ll badmash,deserving,deservingoldidx,bewakoof;
		badmash = arr[i];
		deserving = i;
		bewakoof = arr[badmash];
		deservingoldidx = idx[deserving];
		if(bewakoof!=deserving){//unpaired
			arr[i] = deserving;idx[deserving]=i;wrong--;
			arr[badmash] = badmash;idx[badmash]=badmash;wrong--;
			arr[deservingoldidx] = bewakoof;idx[bewakoof]=deservingoldidx;if(deservingoldidx==bewakoof) wrong--;
			ans.push_back(i);
			ans.push_back(badmash);
			ans.push_back(deservingoldidx);
			//cout<<"unpaired "<<i<<" "<<badmash<<" "<<deservingoldidx<<endl;
		}else{//paired
			continue;
			arr[i] = deserving;idx[deserving]=i;wrong--;
			ll newidx;
			for(j=n;j>i;j--){
				if(arr[j]!=j && j!=badmash) {
					ll num = arr[j];
					if(arr[num]==j){
					newidx = j;
					break;
					}
				}
			}
			if(j==i){
				cout<<-1<<endl;
				return;
			}
			ll chutiya = arr[newidx];
			arr[newidx] = badmash;idx[badmash]=newidx;if(newidx==badmash)wrong--;
			arr[badmash] = chutiya;idx[chutiya]=badmash;if(badmash==chutiya) wrong--;
			ans.push_back(i);
			ans.push_back(newidx);
			ans.push_back(badmash);
			//cout<<"paired "<<i<<" "<<newidx<<" "<<badmash<<endl;
		}
		m++;
	}
	for(ll ii=1;true;ii++){
		i=ii%n;if(i==0) i=n;
		if(wrong==2){
			cout<<-1<<endl;
			return;
		}
		else if(wrong==0){
			break;
		}
		if(arr[i]==i) continue;
		//tripple swapping
		ll badmash,deserving,deservingoldidx,bewakoof;
		badmash = arr[i];
		deserving = i;
		bewakoof = arr[badmash];
		deservingoldidx = idx[deserving];
		if(bewakoof!=deserving){//unpaired
			arr[i] = deserving;idx[deserving]=i;wrong--;
			arr[badmash] = badmash;idx[badmash]=badmash;wrong--;
			arr[deservingoldidx] = bewakoof;idx[bewakoof]=deservingoldidx;if(deservingoldidx==bewakoof) wrong--;
			ans.push_back(i);
			ans.push_back(badmash);
			ans.push_back(deservingoldidx);
			//cout<<"unpaired "<<i<<" "<<badmash<<" "<<deservingoldidx<<endl;
		}else{//paired
			arr[i] = deserving;idx[deserving]=i;wrong--;
			ll newidx;
			for(j=1;j<=n;j++){
				if(arr[j]!=j && j!=badmash && j!=i) {
					newidx = j;
					break;
				}
			}
			if(j==n+1){
				cout<<-1<<endl;
				return;
			}
			ll chutiya = arr[newidx];
			arr[newidx] = badmash;idx[badmash]=newidx;if(newidx==badmash)wrong--;
			arr[badmash] = chutiya;idx[chutiya]=badmash;if(badmash==chutiya) wrong--;
			ans.push_back(i);
			ans.push_back(newidx);
			ans.push_back(badmash);
			//cout<<"paired "<<i<<" "<<newidx<<" "<<badmash<<endl;
		}
		m++;
	}
	//if(m>kk){
		//cout<<-1<<endl;
		//return;
	//}
	cout<<m<<endl;
	for(i=0;i<ans.size();i+=3){
		cout<<ans[i]<<" "<<ans[i+1]<<" "<<ans[i+2]<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i =1 ;i<=t;i++) solve();
	return 0;
}
