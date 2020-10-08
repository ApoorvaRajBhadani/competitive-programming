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
bool check(ll r,ll g,ll b,ll w){
    ll c=0;
    if(r%2==0) c++;
    if(g%2==0) c++;
    if(b%2==0) c++;
    if(w%2==0) c++;
    if(c>=3) return true;
    return false;
}
void solve(ll caseno){
	ll i,j,r,g,b,w;
    cin>>r>>g>>b>>w;
    //case 1
    bool ans1 = check(r,g,b,w);
    //case 2
    bool ans2 = false;
    if(r>0 && g>0 && b>0) ans2 = check(r-1,g-1,b-1,w+3);
    if(ans1 || ans2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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
