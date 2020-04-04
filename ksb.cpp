#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int arr[50][30];

ll findMax(ll row,ll left,ll n){
	ll i,ans=0;
	if(row==(n)) return 0;
	if(left<0) return -1;
	if(left==0) return 0;
	for(i=-1;i<left;i++){
		ll t=0;
		if(i!=-1) t += arr[row][i];
		ll fromfun = findMax(row+1,left-(i+1),n);
		if(fromfun==-1) break;
		else t+=fromfun;
		ans = max(ans,t);
	}
	return ans;
}

void solve(int caseno){
	ll n,k,p,i,j;
	cin>>n>>k>>p;
	memset(arr,0,sizeof(arr));
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			cin>>arr[i][j];
			if(j>0) arr[i][j] += arr[i][j-1];
		}
	}
	ll ans =findMax(0,p,n);
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
