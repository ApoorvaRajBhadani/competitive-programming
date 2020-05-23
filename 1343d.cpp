#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,k,a,i,j,c=0;
	cin>>n>>k;
	ll arr[n+1];
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll mxtodec=LLONG_MIN,mxtoinc=LLONG_MAX,mn=LLONG_MAX;
	ll* mode = new ll[2*k+1]();
	ll* pref = new ll[2*k+2]();
	for(i=1;i<=(n/2);i++){
		ll sum = arr[i] + arr[n-i+1];
		mode[sum]++;
		pref[min(arr[i]+1,arr[n-i+1]+1)]++;
		pref[max(arr[i]+k,arr[n-i+1]+k)+1]--;
	}
	ll pre=0;
	for(i=2;i<=2*k;i++){
		pre = pre+pref[i];
		mn= min(mn, (pre-mode[i])+2*(n/2 - pre));
	}
	cout<<mn<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
