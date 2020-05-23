#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007//998244353
#define p_b push_back
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
void solve(){
	ll i,j,n,ans=0;
	cin>>n;
	while(n>=1){
		ans+=n;
		if(n==1) break;
		bool mila=false;
		for(i=2;i*i<=n;i++){
			if(n%i==0){
				//i is prime;
				n/=i;
				mila=true;
				break;
			}
		}
		if(!mila) n/=n;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//sieve();
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
