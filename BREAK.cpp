#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
#define tezz ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve1(){
		ll n,i;
		cin>>n;
		ll a[n],b[n];
		fo(i,0,n-1) cin>>a[i];
		fo(i,0,n-1) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		map<ll,ll> mp;
		for(i=0;i<n;i++){
			if(!(b[i]>a[i])){
				cout<<"NO\n";
				return;
			}
			if(mp[a[i]]==0 && i!=0){
				cout<<"NO\n";
				return;
			}
			mp[a[i]]++;
			mp[b[i]]++;
		}
		cout<<"YES\n";
}

void solve2(){
}

int main(){
	tezz
	ll t,s;
	cin>>t>>s;
	if(s==1) while(t--) solve1();
	else while(t--) solve2();
	return 0;
}
