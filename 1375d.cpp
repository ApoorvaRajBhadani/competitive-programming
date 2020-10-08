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
ll arr[1005];
void solve(ll caseno){
	ll i,j,n;
    cin>>n;
    vi ans;
    fo(i,0,n) cin>>arr[i];
    ll mex=0;
    while(true){
        vector<bool> pres(n+1,false);
        fo(i,0,n){
            pres[arr[i]]=true;
        }
        fo(i,0,n+1){
            if(!pres[i]) {
            	mex=i;
            	break;
            }
        }
        //cout<<mex<<endl;
        if(mex==n){
            break;
        }
        arr[mex]=mex;
        ans.pbb(mex+1);
    }
    while(true){
        vector<bool> pres(n+1,false);
        fo(i,0,n){
            pres[arr[i]]=true;
        }
        fo(i,0,n+1){
            if(!pres[i]) {
            	mex=i;
            	break;
            }
        }
        //cout<<mex<<endl;
        if(mex==n){
            break;
        }
        arr[mex]=mex;
        ans.pbb(mex+1);
    }
    cout<<ans.size()<<endl;
    for(auto idx:ans) cout<<idx<<' ';
    cout<<endl;
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
