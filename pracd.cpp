#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	ll n;
	cin>>n;
	cin>>s;
	ll seat=0,fris=0;
	ll prev = s[0];
	for(ll i=1;i<s.size();i++){
		if(s[i]!=prev){
			if(prev == 'S') seat++;
			else fris++;
		}
		prev = s[i];
	}
	if(seat>fris) cout<<"YES"<<endl;
	else cout<<"NO";
	return 0;
}
