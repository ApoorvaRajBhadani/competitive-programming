#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int main(){
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	ll a[n+1],b[n+1];
    	fo(i,1,n)cin>>a[i]>>b[i];
    	ll h[n+1];
    	fo(i,1,n){
    		ll prvb;
    		if(i==1)prvb=b[n];
    		else prvb=b[i-1];
    		if(a[i]<=prvb)h[i]=a[i];
    		else h[i]=prvb;
		}
		int ind=1;
    	fo(i,1,n){
    		if(h[i]<h[ind])
    		ind=i;
		}
		ll ans=0;
		fo(i,1,n){
			ans+=a[i]-h[i];
		}
    	ans+=h[ind];
    	cout<<ans<<'\n';
	}
	return 0;
}
