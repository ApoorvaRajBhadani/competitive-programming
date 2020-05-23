#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,j,mn=LLONG_MAX,mx=LLONG_MIN;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	ll prev=arr[0];
	ll myset=1;
	for(i=1;i<n;i++){
		if(abs(arr[i]-prev)>2){
			mx = max(mx,myset);
			mn = min(mn,myset);
			myset=1;
		}else{
			myset++;
		}
		prev=arr[i];
	}
	mx = max(mx,myset);
	mn = min(mn,myset);
	cout<<mn<<" "<<mx<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
