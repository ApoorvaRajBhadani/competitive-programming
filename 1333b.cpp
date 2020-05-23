#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i;
	cin>>n;
	ll a[n],b[n],lastplus[n],lastminus[n];
	ll lp=INT_MAX,lm=INT_MAX;
	for(i=0;i<n;i++){
		cin>>a[i];
		lastplus[i]=lp;
		lastminus[i]=lm;
		if(a[i]==1) lp=i;
		if(a[i]==-1) lm=i;
	}
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	for(i=n-1;i>=0;i--){
		if(b[i]-a[i] > 0){
			if(!(lastplus[i]<i)) {
				cout<<"NO"<<endl;
				return;
			}
		}else if(b[i]-a[i] <0){
			if(  !(lastminus[i]<i)){
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}











