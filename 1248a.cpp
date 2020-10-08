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
ll arrp[100005],arrq[100005];
void solve(ll caseno){
	ll i,j,n,m,no=0,ne=0,ans=0;
    cin>>n;
    fo(i,0,n) cin>>arrp[i];
    cin>>m;
    fo(i,0,m) {
        cin>>arrq[i];
        if(arrq[i]%2==0) ne++;
        else no++;
    }
    fo(i,0,n) {
        //cout<<"he"<<endl;
        if(arrp[i]%2==0){
            ans+=ne;
        }else{
            ans+=no;
        }
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
