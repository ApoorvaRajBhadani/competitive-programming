#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	int n,i,mn=INT_MAX,mx=0;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
		mn = min(mn,arr[i]);
		mx = max(mx,arr[i]);
	}
	cout<<mx-mn+1 - n;
return 0;
}
