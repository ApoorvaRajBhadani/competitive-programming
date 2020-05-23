#include<bits/stdc++.h> 
using namespace std;
typedef int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,n,q;
	cin>>n>>q;
	multiset <ll, greater <ll> > mst;  
	fo(i,0,n-1){
		cin>>j;
		mst.insert(j);
	}
	while(q--){
		ll k;
		cin>>k;
		if(k<0){
			auto ms_iterator = mst.begin(); 
			fo(j,1,abs(k)-1) ms_iterator++;
			mst.erase(ms_iterator);
		}else{
			mst.insert(k);
		}
	}
	if(mst.size()==0){
		cout<<0<<endl;
	}else{
		auto msit = mst.begin();
		cout<<*msit<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
