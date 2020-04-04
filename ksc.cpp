#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool compare(ll a,ll b){
	return a>b;
}
void solve(int caseno){
	ll n,i,k;
	cin>>n>>k;
	ll* arr = new ll[n-1];
	ll prev,curr;
	cin>>prev;
	for(i=0;i<(n-1);i++){
		cin>>curr;
		arr[i] = curr - prev;
		//cout<<arr[i]<<" ";
		prev = curr;
	}
	//cout<<endl;
	sort(arr,arr+(n-1),compare);
	ll a,b;
	a = arr[0];
	b=arr[1];
	if(a%2==0) a = a/2;
	else a = a/2 + 1;
	ll ans = max(b,a);
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
