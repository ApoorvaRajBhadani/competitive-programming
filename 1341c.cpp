#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,j;
	cin>>n;
	ll* arr = new ll[n+2];
	ll dots[n+2],fwd[n+2],bkwd[n+2],mark[n+2];
	stack<pair<ll,ll>> best;best.push(make_pair(0,0));
	ll mp[n+1];
	for(i=1;i<=n;i++){
		cin>>arr[i];
		dots[i]=1;
		mark[i]=false;
		best.push(make_pair(1,i));
		mp[arr[i]]=i;
	}
	mark[n+1]=mark[0]=false;
	for(i=1;i<=n;i++){
		ll idx = mp[i];
		//cout<<i<<" "<<idx<<endl;
		ll besht;
		do{
			if(mark[best.top().second]){
				best.pop();
			}else{
				besht = best.top().first;
				break;
			}
		}while(true);
		if(dots[idx]<besht){
			cout<<"No"<<endl;
			return;
		}
		mark[idx]=true;
		if(mark[idx+1]) fwd[idx] = fwd[idx+1];
		else fwd[idx]=idx+1;
		if(mark[idx-1]) bkwd[idx] = bkwd[idx-1];
		else bkwd[idx] = idx-1;
		if(fwd[idx]!=n+1){
			dots[fwd[idx]] = fwd[idx] - bkwd[idx];
			if(dots[fwd[idx]]>=besht){
				best.push(make_pair(dots[fwd[idx]],fwd[idx]));
			}
		}
	}
	cout<<"Yes"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
