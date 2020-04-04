#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(int caseno){
	ll n,b,i,q=0;
	cin>>n>>b;
	ll arr[n];
	for(i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	for(i=0;i<n;i++){
		if(arr[i]>b) break;
		b-=arr[i];
		q++;
	}
	cout<<"Case #"<<caseno<<": "<<q<<endl;
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
