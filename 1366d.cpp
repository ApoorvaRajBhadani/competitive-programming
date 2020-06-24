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
ll spf[10000005];
void sieve(){
	ll i,j;
	fo(i,0,10000005) spf[i]=i;
	for(i=4;i<=10000000;i+=2) spf[i]=2;
	for(i=3;i*i<=10000000;i++){
		if(spf[i]==i){
			for(j=i*i;j<=10000000;j+=i){
				if(spf[j]==j)spf[j]=i;
			}
		}
	}
}
vector<ll> line1,line2;
void solve(){
	ll i,j,n,mul=1,d1;
	cin>>n;
	d1=spf[n];
	set<ll> st;
	while(n!=1){
		st.insert(spf[n]);
		n/=spf[n];
	}
	if(st.size()==1){
		//-1
		line1.pbb(-1);
		line2.pbb(-1);
	}else{
		for(auto num:st) mul*=num;
		line1.pbb(d1);
		line2.pbb(mul/d1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	sieve();
	ll t=1;
	cin>>t;
	while(t--){
		solve();
	}
	for(auto d1:line1) cout<<d1<<" ";
	cout<<endl;
	for(auto d2:line2) cout<<d2<<" ";
	return 0;
}
