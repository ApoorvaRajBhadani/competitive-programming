#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,n;
	cin>>n;
	double alpha = 3.141592653589/(2*n);
	double ans = (1/pow(2,0.5))*(1+2*sin(3.141592653589*(n-1)/(2*n)));
	cout << fixed << setprecision(9) << ans<<endl; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}
