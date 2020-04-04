#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,i;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	ll x=0;
	for(i=0;i<n;i++){
		ll a;
		a = x+arr[i];
		cout<<a<<" ";
		x = max(x,a);
	}
	return 0;
}
