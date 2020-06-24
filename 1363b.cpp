#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))

void solve(){
	ll i,j,n,ans=INT_MAX;
	string s;
	cin>>s;
	n = s.size();
	ll dpl0[n],dpl1[n],dpr0[n+1],dpr1[n+1];
	dpr0[n]=dpr1[n]=0;
	dpl0[0] = s[0]-'0';
	dpl1[0] = 1-dpl0[0];
	fo(i,1,n){
		dpl0[i]=dpl0[i-1];
		if(s[i]=='1') dpl0[i]++;
		dpl1[i]=dpl1[i-1];
		if(s[i]=='0') dpl1[i]++;
	}
	dpr0[n-1] = s[n-1]-'0';
	dpr1[n-1] = 1-dpr0[n-1];
	for(i=n-2;i>=0;i--){
		dpr0[i]=dpr0[i+1];
		if(s[i]=='1') dpr0[i]++;
		dpr1[i]=dpr1[i+1];
		if(s[i]=='0') dpr1[i]++;
	}
	ans = min(ans,dpr0[0]);
	ans = min(ans,dpr1[0]);
	fo(i,0,n){
		//111100000
		ans = min(ans,dpl1[i]+dpr0[i+1]);
		//000011111
		ans = min(ans,dpl0[i]+dpr1[i+1]);
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}
