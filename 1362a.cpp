#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
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

void solve(){
	ll i,j,n;
	cin>>n;
	set<ll> st;
	fo(i,0,n){
		cin>>j;
		st.insert(j);
	}
	for(i=1;i<=1024;i++){
		set<ll> nst;
		for(auto num:st){
			nst.insert(num^i);
		}
		if(nst==st){
			cout<<i<<endl;
			return;
		}
	}
	cout<<-1<<endl;
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
