#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		if(k%2==0){
			if(n%2==0 && n>=k*k){
				cout<<"YES\n";
			}
			else cout<<"NO\n";
		}else{
			if(n%2==1 && n>=k*k){
				cout<<"YES\n";
			}else cout<<"NO\n";
		}
	}
	return 0;
}
