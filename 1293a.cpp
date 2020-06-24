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

void solve(ll caseno){
	ll i,j,n,s,k;
    cin>>n>>s>>k;
    set<ll> closed;
    fo(i,0,k) {
        cin>>j;
        closed.insert(j);
    }
    for(i=0;i<=1005;i++){
        ll left = max(1ll,s-i);
        ll right = min(n,s+i);
        if(closed.find(left)==closed.end()){
            cout<<i<<endl;
            return;
        }
        if(closed.find(right)==closed.end()){
            cout<<i<<endl;
            return;
        }
    }
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
