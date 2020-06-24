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
	ll i,j,n,mx=0,k=0;
    cin>>n;
    fo(i,0,n) cin>>arr[i];
    vi diff;
    fo(i,0,n-1){
        if(arr[i]>=0 && arr[i+1]>=0) mx=max(mx,abs(arr[i]-arr[i+1]));
        else if(arr[i]>=0 && arr[i+1]==-1) diff.pbb(arr[i]);
        else if(arr[i]==-1 && arr[i+1]>=0) diff.pbb(arr[i+1]);
    }
    if(diff.size()>0){
        sort(all(diff));
        k=(diff[0]+diff[diff.size()-1])/2;
        mx=max(mx,max(diff[diff.size()-1]-k,k-diff[0]));
    }
    cout<<mx<<" "<<k<<endl;
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
