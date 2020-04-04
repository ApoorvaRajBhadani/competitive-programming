#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define pb push_back
int main(){
	int n,t;
	cin>>n;
	vector<int> o,e;
	for(int i =1;i<=n;i++){
		cin>>t;
		if(t&1) o.pb(i);
		else e.pb(i);
	}
	if(o.size() == 1) cout<<o[0];
	else cout<<e[0];
	return 0;
}
