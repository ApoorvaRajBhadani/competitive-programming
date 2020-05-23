#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,j,a,sum=0,last=0,prevtype=1;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		if(a/abs(a) != prevtype){
			sum+=last;
			last=LLONG_MIN;
		}
		last = max(last,a);
		prevtype = a/abs(a);
	}
	sum+=last;
	cout<<sum<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
