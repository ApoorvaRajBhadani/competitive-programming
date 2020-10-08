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
	ll i,j,n,p=0,total=0;
    string s;
    cin>>n>>s;
    vi pos,ps(n),ans(n,0);
    fo(i,0,n){
        int b =s[i]-'0';
        p+=b;
        ps[i]=p;
        if(b==0){
            for(auto pi:pos){
                if(i-pi+1==ps[i]-(pi-1>=0?ps[pi-1]:0)) ans[i]++;
            }
        }else{
            pos.pbb(i);
            ll mysum = ps[i]-(i-b>=0?ps[i-b]:0);
            if(mysum==b && i>=b-1) {
                ans[i]++;
                if(i-b>=0) ans[i]+=ans[i-b];
            }
        }
        total+=ans[i];
        //cout<<ans[i]<<endl;
    }
    cout<<total<<endl;
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
