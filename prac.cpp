#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	string s;
	ll n,i,j;
	cin>>s;
	n = s.length();
	for(i=0;i<n;i++){
		if(s[i]>='5'){
			s[i] = '0' + (9 - (s[i]-'0'));
		}
	}
	if(s[0]=='0') s[0]='9';
	cout<<s<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	t=1;//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
