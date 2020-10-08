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
ll pos[200005];
ll arr[200005];
bool ans[200005];
void solve(ll caseno){
	ll i,j,n;
    cin>>n;
    mset(pos,0);
    mset(arr,0);
    fo(i,0,n){
        cin>>j;
        arr[i]=j;
        pos[j]=i;
    }
    mset(ans,0);
    ll l=pos[1],r=pos[1],mx=1;
    while(r-l+1!=n){
        cout<<l<<" "<<r<<"1"<<endl;
        if(mx==(r-l+1)) ans[mx]=true;
        ll nxtpos=pos[mx+1];
        if(nxtpos>=l&&nxtpos<=r) mx++;
        if(nxtpos>r){
            while(r<nxtpos){
                cout<<l<<" "<<r<<'2'<<endl;
                r++;
                mx=max(mx,arr[r]);
                if(mx==(r-l+1)) ans[mx]=true;
            }
        }else if(nxtpos<l){
            while(l>nxtpos){
                cout<<l<<" "<<r<<'3'<<endl;
                l--;
                mx=max(mx,arr[l]);
                if(mx==(r-l+1)) ans[mx]=true;
            }
        }
    }
    fo(i,1,n+1) cout<<ans[i];cout<<endl;
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
