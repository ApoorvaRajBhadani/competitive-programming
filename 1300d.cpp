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
ll x[100005],y[100005];
void solve(ll caseno){
	ll i,j,n;
    cin>>n;
    if(n%2==1){
        cout<<"NO"<<endl;
		return;
    }
	fo(i,0,n){
		cin>>x[i]>>y[i];
	}
	double xm,ym;
	xm=(x[0]+x[n/2]);
	ym=(y[0]+y[n/2]);
	fo(i,1,n/2){
		double myxm,myym;
		myxm=(x[i]+x[i+n/2]);
		myym=(y[i]+y[i+n/2]);
		if(xm!=myxm||ym!=myym){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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
