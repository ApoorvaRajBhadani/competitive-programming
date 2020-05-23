#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,q,i;
	string s;
	cin>>n>>q>>s;
	ll freq[26];
	for(i=0;i<26;i++) freq[i]=0;
	for(i=0;i<n;i++) freq[s[i]-'a']++;
	while(q--){
		ll c,ans=0;
		cin>>c;
		for(i=0;i<26;i++){
			if(freq[i]>c) ans+=freq[i]-c;
		}
		cout<<ans<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
