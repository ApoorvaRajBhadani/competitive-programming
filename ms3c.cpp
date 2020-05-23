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
	ll i,j,n;
	cin>>n;
	if(n>=0){
		cout<<n<<endl;
	}else{
		n=-n;
		ll a = n/10;
		ll b = (n%10)+((n/100)*10);
		cout<<-1*min(a,b)<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
