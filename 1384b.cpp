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
int dp[210][210];
ll dep[110];
ll p[210];
ll n,k,l;
bool answer(ll idx,ll t){
    if(idx==n+1) return 1;//base case
    if(dp[idx][t]>=0) return dp[idx][t];//using dp value
    if(dep[idx]+p[t] > l) return dp[idx][t]=0;//critical case
    dp[idx][t]=0;
    bool ans = answer(idx+1,(t+1)%(2*k)) || answer(idx,(t+1)%(2*k));//ans from rec
    return dp[idx][t] = ans;
}
void solve(ll caseno){
	ll i,j;
    cin>>n>>k>>l;
    fo(i,1,n+1) cin>>dep[i];
    for(i=0;i<=k;i++) p[i]=i;
    for(;i<2*k;i++) p[i]=p[i-1]-1;
    dep[0]=dep[n+1]=INT_MIN;
    mset(dp,-1);
    bool ans = answer(0,0);
    cout<<(ans?"Yes":"No")<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
