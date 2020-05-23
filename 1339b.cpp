#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll lastdif = 0,mid = (n-1)/2;
	i=0;
	while(lastdif<=(n-1)){
		cout<<arr[mid]<<" ";
		lastdif++;
		if(i%2==0)mid+=lastdif;
		else mid-=lastdif;
		i++;
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
