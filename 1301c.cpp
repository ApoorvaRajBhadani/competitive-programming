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
	ll i,j,n,m,b,ans;
    cin>>n>>m;
    if(m==0) {cout<<0<<endl;return;}
    if(n%2==0){
        if(m%2==0){
            b=(n-m)/2;
            ans=(m+b)*b;
            ans+=((b+m+b+1)*m)/2;
        }else{
            b=n/2-m/2;
            ans=(m+b)*(b-1);
            ans+=((b+m+b+1)*m)/2;
        }
    }else{
        if(m%2==0){
            b=(n-m-1)/2;
            m++;
            ans=(m+b)*b;
            ans+=((b+m+b+1)*m)/2;
            ans--;
        }else{
            b=(n-m)/2;
            ans=(m+b)*b;
            ans+=((b+m+b+1)*m)/2;
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
