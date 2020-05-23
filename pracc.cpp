#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll i,j,sum=0;
	vector<ll> vec;
	for(i=0;i<n;i++){
		cin>>j;
		if(j%2==0) sum+=j;
		else vec.push_back(j);
	}
	sort(vec.begin(),vec.end(),greater<ll>());
	if(vec.size()%2==0){
		for(i=0;i<vec.size();i++) sum+=vec[i];
	}else{
		for(i=0;i<vec.size()-1;i++) sum+=vec[i];
	}
	cout<<sum<<endl;
	return 0;
}
