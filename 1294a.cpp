#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll; 
int main(){
	ll arr[3],t,n,dis;
	cin>>t;
	while(t--){
		cin>>arr[0]>>arr[1]>>arr[2]>>n;
		sort(arr,arr+3);
		dis = arr[2]-arr[1]+arr[2]-arr[0];
		if((n-dis)%3==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
