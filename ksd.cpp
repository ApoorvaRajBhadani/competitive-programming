#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll findAns(string* arr,ll n,ll k,vector<ll> vec,ll colno,bool* presence){
	map<char,pair<ll,vector<ll>>> mp;
	ll ans = 0;
	for(auto it = vec.begin();it!=vec.end();it++){
		if(colno< arr[*it].size() && presence[*it]){
			mp[arr[*it][colno]].first++;
			mp[arr[*it][colno]].second.push_back(*it);
		}
	}
	for(auto it = mp.begin();it!=mp.end();it++){
		ll qt = (*it).second.first;
		while(qt>=k){
			//cout<<qt<<" ";
			ll ttt = findAns(arr,n,k,(*it).second.second,colno+1,presence);
			qt-=k;
			ans+= 1 + ttt;
		}
	}
	for(auto it = vec.begin();it!=vec.end();it++){
		presence[*it] = false;
	}
	return ans;
}
void solve(int caseno){
	ll n,k,i,ans=0;
	cin>>n>>k;
	string* arr = new string[n];
	bool* presence = new bool[n];
	vector<ll> vec;
	for(i=0;i<n;i++) {cin>>arr[i];vec.push_back(i);presence[i] = true;}
	ans = findAns(arr,n,k,vec,0,presence);
	cout<<"Case #"<<caseno<<": "<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
