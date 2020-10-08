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
string s;
ll answer(ll l,ll r,char c){
    if(l==r){
        if(s[l]==c) return 0;
        else return 1;
    }
    ll ans1=0,ans2=0,n,i,j;
    n = r-l+1;
    for(i=0,j=l;i<n/2;i++,j++){
        if(s[j]!=c) ans1++;
    }
    ans1+=answer(l+(n/2),r,c+1);
    for(i=0,j=l+(n/2);i<n/2;i++,j++){
        if(s[j]!=c) ans2++;
    }
    ans2+=answer(l,l+(n/2)-1,c+1);
    return min(ans1,ans2);
}
void solve(ll caseno){
	ll i,j,n,ans;
    cin>>n>>s;
    ans = answer(0,n-1,'a');
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
