#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,j,c=0;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=1;i<=(n-2);i++){
		if((arr[i]> arr[i+1]) &&(arr[i]>arr[i-1])) c++;
	}
	cout<<c<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
