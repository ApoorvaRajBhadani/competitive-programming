#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,n,k,c=0;
	cin>>n>>k;
	ll arr[n];
	ll nextreq=k;
	fo(i,0,n-1){
		cin>>arr[i];
	}
	fo(i,0,n-1){
		if(arr[i]==nextreq){
			nextreq--;
			if(nextreq==0){
				c++;
				nextreq=k;
			}
		}else{
			nextreq=k;
			if(arr[i]==k) nextreq--;
		}
	}
	cout<<c<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
