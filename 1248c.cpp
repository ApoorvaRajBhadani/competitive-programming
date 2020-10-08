#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
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
ll dp[100005][4];
void precomp(){
    dp[2][0]=dp[2][1]=dp[2][2]=dp[2][3]=1;
    for(ll i=3;i<=100000;i++){
        dp[i][0]=dp[i-1][2];
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2]=(dp[i-1][1]+dp[i-1][3])%MOD;
        dp[i][3]=dp[i-1][1];
    }
}
ll linearans(ll n){
    if(n==0) return 0;
    if(n==1) return 2;
    ll i,ans=0;
    fo(i,0,4){
        ans=(ans+dp[n][i])%MOD;
    }
    return ans;
}
void solve(ll caseno){
	ll i,j,n,m,ans;
    cin>>n>>m;
    ll lans=linearans(n);
    ans=(lans-2)+linearans(m);
    ans%=MOD;
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    precomp();
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
