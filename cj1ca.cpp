#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll W,S,i;
	string tour;
	cin>>W>>S>>tour;
	for(i=0;i<tour.length();i++){
		if(tour[i]=='W') {
			W--;
		}else if(tour[i]=='S') {
			S--;
		}else if(tour[i]=='N'){
			S++;
		}else if(tour[i]=='E'){
			W++;
		}
		if(abs(W)+abs(S)<=i+1){
			cout<<i+1<<endl;
			return;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
