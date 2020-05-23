#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,n;
	cin>>n;
	ll arr[n];
	fo(i,0,n-1) cin>>arr[i];
	ll ap=0,bp=n-1,moves=0,last=0,aate=0,bate=0,chance=0;
	while(ap<=bp){
		moves++;
		ll iate = 0;
		if(chance==0){
			while(iate<=last && ap<=bp){
				iate+=arr[ap];
				arr[ap]=0;
				ap++;
			}
			aate+=iate;
		}else{
			while(iate<=last && ap<=bp){
				iate+=arr[bp];
				arr[bp]=0;
				bp--;
			}
			bate+=iate;
		}
		last = iate;
		chance^=1;
	}
	cout<<moves<<" "<<aate<<" "<<bate<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
