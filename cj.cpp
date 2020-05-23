#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n;
	cin>>n;
	if(n==1){
		cout<<1<<" "<<1<<endl;
	}else if(n==2){
		cout<<1<<" "<<1<<endl;
		cout<<2<<" "<<1<<endl;
	}else if(n==3){
		cout<<1<<" "<<1<<endl;
		cout<<2<<" "<<1<<endl;
		cout<<3<<" "<<1<<endl;
	}else if(n==4){
		cout<<1<<" "<<1<<endl;
		cout<<2<<" "<<1<<endl;
		cout<<3<<" "<<2<<endl;
	}else{
		cout<<1<<" "<<1<<endl;
		cout<<2<<" "<<1<<endl;
		cout<<3<<" "<<2<<endl;
		n-=4;
		ll s=3;
		while(n>0){
			cout<<s<<" "<<1<<endl;
			s++;
			n--;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<":\n";
		solve();
	}
	return 0;
}
