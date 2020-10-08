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
ll arr[200005];
void solve(ll caseno){
	ll i,j,n,p=1,dp=0;
    cin>>n;
    fo(i,0,n) cin>>arr[i];
    for(i=n-1;i>=1;i--){
        ll c;
        if(arr[i-1]>arr[i]) c=1;
        else if(arr[i-1]<arr[i]) c=-1;
        else c=p;
        //cout<<c<<" "<<p<<endl;
        if(c!=p){
            dp++;
        }
        p=c;
        if(dp==2){
            cout<<i<<endl;
            return;
        }
    }
    cout<<0<<endl;
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
