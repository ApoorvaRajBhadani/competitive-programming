#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j;
	string s;
	cin>>s;
	vector<ll> ones,twos,threes;
	fo(i,0,s.size()-1){
		if(s[i]=='1') ones.push_back(i);
		else if(s[i]=='2') twos.push_back(i);
		else if(s[i]=='3') threes.push_back(i);
	}
	if(ones.size()==0||twos.size()==0||threes.size()==0) {
		cout<<0<<endl;
		return;
	}
	ones.push_back(INT_MAX);
	twos.push_back(INT_MAX);
	threes.push_back(INT_MAX);
	ll ans = LLONG_MAX;
	fo(i,0,s.size()-1){
		if(s[i]=='1'){
			auto a = upper_bound(twos.begin(),twos.end(),i);
			auto b= upper_bound(threes.begin(),threes.end(),i);
			ans = min(ans,max(*a,*b)-i+1);
		}else if(s[i]=='2'){
			auto a = upper_bound(ones.begin(),ones.end(),i);
			auto b= upper_bound(threes.begin(),threes.end(),i);
			ans = min(ans,max(*a,*b)-i+1);
		}else if(s[i]=='3'){
			auto a = upper_bound(twos.begin(),twos.end(),i);
			auto b= upper_bound(ones.begin(),ones.end(),i);
			ans = min(ans,max(*a,*b)-i+1);
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}
