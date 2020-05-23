#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i;
	cin>>n;
	ll arr[n+1];
	ll visited[n+1];
	for(i=1;i<=n;i++){
		cin>>arr[i];
		visited[i]=false;
	}
	vector<pair<ll,ll>> vp;
	//for(i=1;i<=n;i++){
		//if(visited[i]==false && arr[i]>0){
			//ll start = i,next;
			//while(true){
				//visited[start];
				//if(arr[start]==0){
					//if(blank.size()==0) arr[start]=i;
					//else{
						//ll nxtblk = blank.front();blank.pop();
						//if(visited[nxtblk]) {
							//if(blank.size()==0) nxtblk=i;
							//else nxtblk = blank.front();blank.pop();
						//}
						//arr[start]=nxtblk;
					//}
				//}
				//next = arr[start];
				//if(next==i) break;
			//}
		//}
	//}
	for(i=1;i<=n;i++){
		if(!visited[i]&&arr[i]>0){
			ll start = i;
			while(true){
				visited[start]=true;
				ll next = arr[start];
				if(visited[next]){
					auto it = find(vp.begin(),vp.end(),next);
					it.first = start;
					break;
				}else if(next==0){
					vp.push_back(make_pair(i,start));
					break;
				}else if(next==i){
					break;
				}
				start = next;
			}
		}
	}
	vector<ll> notused;
	for(i=1;i<=n;i++){
		if(!visited[i]) notused.push_back(i);
	}
	for(i=0;i<vp.size();i++){
		ll e = vp[i].second;
		ll s = vp[i].first;
		cout<<" "<<e<<endl;
	}
	for(i=0;i<vp.size()-1;i++){
		ll e = vp[i].second;
		arr[e] = vp[i+1].first;
	}
	for(i=0;i<notused.size()-1;i++){
		arr[notused[i]] = notused[i+1];
	}
	if(notused.size()>0 && vp.size()>0) {
		arr[notused[notused.size()-1]]=vp[0].first;
		arr[vp[vp.size()-1].second] = notused[0];
	}else if(notused.size()>0 && vp.size()==0){
		arr[notused[notused.size()-1]]= notused[0];
	}else if(notused.size()==0 && vp.size()>0){
		arr[vp[vp.size()-1].second]=vp[0].first;
	}
	for(i=1;i<=n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	t=1;//cin>>t;
	while(t--) solve();
	return 0;
}
