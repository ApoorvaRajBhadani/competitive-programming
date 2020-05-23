#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007//998244353
#define p_b push_back
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,n,m;
	cin>>n>>m;
	ll t[n],s[n],e[n];
	fo(i,0,n-1) cin>>t[i]>>s[i]>>e[i];
	ll prevtime=0,ps=m,pe=m;
	fo(i,0,n-1){
		ll maxdif = t[i]-prevtime;
		ll minto = ps-maxdif;
		ll maxto = pe+maxdif;
		if(e[i]<minto){
			cout<<"NO"<<endl;
			return;
		}else if(s[i]>maxto){
			cout<<"NO"<<endl;
			return;
		}else if(s[i]>=minto && s[i]<=maxto && e[i]>=minto && e[i]<=maxto){
			ps=s[i];
			pe=e[i];
		}else if(e[i]>=minto && e[i]<=maxto && s[i]<=minto){
			ps=minto;
			pe = e[i];
		}else if(s[i]>=minto && s[i]<=maxto && e[i]>=maxto){
			ps=s[i];
			pe=maxto;
		}
		
		//if(minto<=e[i] && s[i]<=maxto){
			//ps = max(minto,s[i]);
			//pe = min(maxto,e[i]);
		//}else{
			//cout<<"NO"<<endl;
			//return;
		//}
		prevtime = t[i];
	}
	cout<<"YES"<<endl;
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
