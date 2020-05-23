#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll n,i,j;
	cin>>n;
	if(n<=3) {
		cout<<-1<<endl;
		return;
	}
	if(n%2==0){
		fo(i,2,n) cout<<i++<<" ";
		i=n-3;
		cout<<i<<" ";
		i=i+2;
		cout<<i<<" ";
		i-=4;
		for(;i>=1;i-=2){
			cout<<i<<" ";
		}
		cout<<endl;
	}else{
		fo(i,1,n) cout<<i++<<" ";
		i=n-3;
		cout<<i<<" ";
		i=i+2;
		cout<<i<<" ";
		i-=4;
		for(;i>=1;i-=2){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
