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
bool answer(ll x,ll n,ll k){
    ll i=0,j,oc=0,ec=0;
    //for odd idx val<=x
    for(j=1;i<n&&j<=k;){
        if(j%2==1){
            if(arr[i]<=x){
                oc++;
                i++;j++;
            }else{
                i++;
            }
        }else{
            i++;
            j++;
            oc++;
        }
    }
    i=0;
    //for even idx val<=x
    for(j=1;i<n&&j<=k;){
        if(j%2==0){
            if(arr[i]<=x){
                ec++;
                i++;j++;
            }else{
                i++;
            }
        }else{
            i++;
            j++;
            ec++;
        }
    }
    //cout<<"x="<<x<<" "<<oc<<" "<<ec<<endl;
    if(ec>=k || oc>=k) return true;
    return false;
}
void solve(ll caseno){
	ll i,j,n,k,ans=1e9;
    cin>>n>>k;
    fo(i,0,n) cin>>arr[i];
    ll low=0,high=1e9,mid;
    bool ispos;
    while(low<=high){
        mid=low+(high-low)/2;
        ispos=answer(mid,n,k);
        if(ispos){
            ans=min(ans,mid);
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
