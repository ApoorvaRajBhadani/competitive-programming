#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))

void solve(){
	ll i,j,n;
	cin>>n;
	vector<ll> arr(n);
	fo(i,0,n) cin>>arr[i];
	sort(all(arr));
	ll curr = 1,inhand=0;
	fo(i,0,n){
		if(curr+inhand>=arr[i]){
			curr+=inhand+1;
			inhand=0;
		}else{
			inhand++;
		}
	}
	cout<<curr<<endl;
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
