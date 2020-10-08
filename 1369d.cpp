#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
//#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll dp[2000005];
ll answer(){
    dp[0]=3534;
    dp[1]=0;
    dp[2]=0;
    for(ll i=3;i<=2000000;i++){
        dp[i]=(dp[i-1]+2*dp[i-2])%MOD;
        if(i%3==0) dp[i]=(dp[i]+4)%MOD;
    }
}
void solve(ll caseno){
	ll i,j,n;
    cin>>n;
    cout<<dp[n]<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    answer();
	ll t=1;
	cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
