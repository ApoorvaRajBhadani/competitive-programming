#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define setbits(x) __builtin_popcountll(x)
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll findsum(ll n){
	ll sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
void solve(ll caseno){
	ll i,j,n,s;
	cin>>n>>s;
	ll v=n;
	ll sum = findsum(n);
	ll ans=0,p=1,c=0;
	while(findsum(v+ans)>s){
		//cout<<findsum(v+ans)<<endl;
		n+=c;
		c=0;
		ll b=n%10;
		if(b>0){
			ans+=p*(10-b);
			c=1;
		}
		p*=10;
		n/=10;
	}
	cout<<ans<<endl;
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