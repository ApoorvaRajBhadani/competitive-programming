#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(ll caseno){
	ll i,j,n,k,allones=0,mncost=LLONG_MAX;
	string s;
	cin>>n>>k>>s;
	fo(i,0,n-1) if(s[i]=='1') allones++;
	mncost = allones;
	for(i=0;i<k;i++){
		ll diff=0;
		for(j=i;j<n;j+=k){
			if(s[j]=='1'){
				diff++;
			}else diff--;
			diff=max(0ll,diff);
			mncost = min(mncost,allones-diff);
		}
	}
	cout<<mncost<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
