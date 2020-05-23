#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,j,myc,c=0;
	cin>>n;
	string s;
	cin>>s;
	bool aachuka=false;
	for(i=0;i<n;i++){
		if(s[i]=='A'){
			if(aachuka) c=max(myc,c);
			aachuka = true;
			myc=0;
		}else{
			myc++;
		}
	}
	if(aachuka) c=max(myc,c);
	cout<<c<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
