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
	ll i,j,n,cnt=0;
    string s,ans="",subs="",init="",finale="";
    cin>>n>>s;
    fo(i,0,n){
        if(s[i]=='1') break;
        init+='0';
    }
    for(j=n-1;j>=i;j--){
        if(s[j]=='0') break;
        finale+='1';
    }
    if(j>=i){
        if(j-i+1>=1) subs+='0';
    }
    ans=init+subs+finale;
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
