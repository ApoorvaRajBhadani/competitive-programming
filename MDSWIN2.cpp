#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 998244353
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
#define tezz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
	tezz
	ll t;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n;
		ll arr[n];
		fo(i,0,n-1)cin>>arr[i];
		cin>>q;
		while(q--){
			ll l,r;
			cin>>l;cin>>r;
			l--;r--;
			map<ll,ll> mp;
			fo(i,l,r) mp[arr[i]]++;
			bool flag=false,flag2=false;
			ll m=0;
			for(auto it=mp.begin();it!=mp.end();it++){
				if(it->second > 1){
					if(flag==false) {flag = true; m=it->second;}
					else flag2 = true;
				}
			}
			if(flag){
				if(flag2){
					cout<<0<<endl;
				}
				if(mp.size() %2 ==0) cout<<m%MOD<<endl;
				else cout<<1<<endl;
			}
			else{
				if(mp.size() %2 ==1) {cout<<r-l+1<<endl;}
				else cout<<0<<endl;
			}
		}
	}
	return 0;
}
