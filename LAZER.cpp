#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
#define tezz ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	tezz
	
	ll t;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		ll arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		while(q--){
			ll a,b,y,i,c=0,v1,v2;
			cin>>a>>b>>y;
			a--;b--;
			for(i=a;i<b;i++){
				v1 = arr[i];
				v2 = arr[i+1];
				v1-=y;
				v2-=y;
				if(v1*v2 <= 0) c++;
			}
			cout<<c<<endl;
		}
	}
				
	return 0;
}
