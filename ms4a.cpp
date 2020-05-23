#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))

void solve(){
	ll i,j,n;
	string s;
	cin>>s;
	n= s.size();
	vector<ll> mp(26,0),freq(26,0);
	vector<ll> mnreq(26,0);
	ll ans = INT_MAX;
	fo(i,0,s.size()-1){
		if(freq[s[i]-'a']==0){
			ans = min(ans,max(i+1,n-i));
			mnreq[s[i]-'a'] = i+1;
		}else{
			mnreq[s[i]-'a'] = max(mnreq[s[i]-'a'],i-mp[s[i]-'a']);
		}
		mp[s[i]-'a'] = i;
		freq[s[i]-'a']++;
	}
	fo(i,0,25){
		mnreq[s[i]-'a'] = max(mnreq[s[i]-'a'],n-mp[s[i]-'a']);
		//cout<<mnreq[i]<<endl;
		if(freq[i]>=1) ans = min(ans,mnreq[i]);
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
