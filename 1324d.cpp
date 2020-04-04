#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll i,b,count=0;
	cin>>n;
	vector<ll> arr(n,0);
	for(i=0;i<n;i++) cin>>arr[i];
	for(i=0;i<n;i++){
		cin>>b;
		arr[i]-=b;
	}
	
	sort(arr.begin(),arr.end());
	vector<ll>::iterator it,compit;
	it = upper_bound(arr.begin(),arr.end(),0);
	for(;it!=arr.end();it++){
		//finding the complement
		ll comp = *it * -1;
		//first element greater than complement
		compit = upper_bound(arr.begin(),it,comp);
		count+= it-compit;
	}
	cout<<count;
	return 0;
}
