#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
int t;
cin>>t;
while(t--){
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(i=n-1;i>=0;i--){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
return 0;
}
