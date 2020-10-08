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
ll arr[2000005];
ll kadanes(vi& a){
    ll i,n=a.size();
    if(n==0) return 0;
    ll best=a[0],sum=a[0];
    for(i=1;i<n;i++){
        sum = max(a[i], sum+a[i]); 
        best = max(best, sum); 
    }
    return best;
}
void solve(ll caseno){
	ll i,j,n,sum=0;
    cin>>n;
    fo(i,0,n){
        cin>>arr[i];
    }
    vi right,left;
    for(i=0;i<n;i+=2){
        sum+=arr[i];
        if(i+1<n){
            ll diff=arr[i+1]-arr[i];
            right.pbb(diff);
        }
        if(i-1>=0){
            ll diff=arr[i-1]-arr[i];
            left.pbb(diff);
        }
    }
    ll kd1=kadanes(right);
    ll kd2=kadanes(left);
    sum=max(sum,sum+max(kd1,kd2));
    cout<<sum<<endl;
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
