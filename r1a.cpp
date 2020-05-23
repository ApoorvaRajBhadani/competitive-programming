#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,mx,idx;
	cin>>n;
	vector<string> lvec,rvec;
	string s,ast="*",empt="";
	for(i=0;i<n;i++){
		cin>>s;
		ll found = s.find(ast);
		lvec.push_back(s.substr(0,found));
		if(s.length()-1-found >0) rvec.push_back(s.substr(found+1,s.length()-1-found));
		else rvec.push_back(empt);
	}
	//left check
	mx = 0,idx=0;
	for(i=0;i<n;i++) { if(lvec[i].size() > mx) { mx = lvec[i].size();idx=i;}}
	string pleft = lvec[idx];
	//cout<<pleft<<endl;
	for(i=0;i<n;i++){
		size_t found = pleft.find(lvec[i]); 
		if (found == string::npos || found!=0){
			cout<<"*"<<endl;
			return;
		} 
	}
	mx = 0,idx=0;
	for(i=0;i<n;i++)  reverse(rvec[i].begin(), rvec[i].end()); 
	for(i=0;i<n;i++) { if(rvec[i].size() > mx) { mx = rvec[i].size();idx=i;}}
	string pright = rvec[idx];
	//cout<<pright<<endl;
	for(i=0;i<n;i++){
		size_t found2 = pright.find(rvec[i]); 
		if (found2 == string::npos || found2!=0){
			cout<<"*"<<endl;
			return;
		} 
	}
	reverse(pright.begin(),pright.end());
	cout<<pleft<<pright<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
