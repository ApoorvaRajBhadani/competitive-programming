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
ll a[200005],b[200005],c[200005];
void solve(){
	ll i,j,n,ans=0;
	cin>>n;
	fo(i,0,n){
		cin>>j;
		a[j]=i;
	}
	fo(i,0,n){
		cin>>j;
		b[j]=i;
	}
	mset(c,0);
	Fo(i,1,n){
		ll diff = a[i]-b[i];
		diff = (diff+n)%n;
		c[diff]++;
	}
	fo(i,0,n){
		ans=max(ans,c[i]);
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
