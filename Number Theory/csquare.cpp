#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
//base 3 modular exponentiation
void solve(){
	ll a,c,i,j,ans=1,prev;
	string b;
	cin>>a>>b>>c;
	reverse(b.begin(),b.end());
	prev=a;
	for(i=0;i<b.size();i++){
		ll mul = b[i]-'0';
		while(mul){
			ans = (ans*prev)%c;
			mul--;
		}
		prev=((prev*prev)%c*prev)%c;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
