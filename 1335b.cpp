#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,a,b,i,j;
	cin>>n>>a>>b;
	for(i=0;i<n;i++){
		j = i%b;
		char  c = j + 'a';
		cout<<c;
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
