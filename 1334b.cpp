#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool compare(ll a,ll b){
	return a>b;
}
void solve(){
	ll n,x;
	cin>>n>>x;
	ll mon[n];
	for(ll i=0;i<n;i++){
		cin>>mon[i];
	}
	sort(mon,mon+n,compare);
	ll i,pep=0,sum=0;
	for( i=0;i<n;i++){
		sum+=mon[i];
		if((sum/(i+1)) >= x){
			pep++;
		}else{
			break;
		}
	}
	cout<<pep<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--)solve();
	return 0;
}
