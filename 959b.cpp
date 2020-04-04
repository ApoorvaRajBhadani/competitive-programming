#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,g,wm,i,w,j,x,mn,ans=0,idx;
	string s;
	cin>>n>>g>>wm;
	map<string,ll> mp;
	vector<ll> wordwgt;
	for(i=0;i<n;i++){
		cin>>s;
		mp[s]=i;
	}
	for(i=0;i<n;i++){
		cin>>w;
		wordwgt.push_back(w);
	}
	for(i=0;i<g;i++){
		cin>>x;
		mn=INT_MAX;
		vector<ll> vec;
		for(j=0;j<x;j++){
			cin>>idx;
			vec.push_back(idx);
			mn = min(mn,wordwgt[vec[j]-1]);
		}
		for(j=0;j<x;j++){
			wordwgt[vec[j]-1]=mn;
		}
	}
	for(i=0;i<wm;i++){
		cin>>s;
		idx=mp[s];
		ans+=wordwgt[idx];
	}
	cout<<ans;
	return 0;
}













