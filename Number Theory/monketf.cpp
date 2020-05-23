#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool primes[1000001];
vector<ll> primevec;
void sieve(){
	ll i,j;
	for(i=2;i<=1000000;i++) primes[i]=true;
	primes[0]=primes[1]=false;
	for(i=2;i*i<=1000000;i++){
		if(primes[i]){
			for(j=i*i;j<=1000000;j+=i){
				primes[j]=false;
			}
		}
	}
	primevec.push_back(2);
	for(i=3;i<=1000000;i+=2) if(primes[i]) primevec.push_back(i);
}
void solve(){
	ll l,r,k,i,j,c=0;
	cin>>l>>r>>k;
	ll etf[r-l+1],extraprime[r-l+1];
	for(i=0;i<=(r-l);i++){
		extraprime[i]=etf[i]=i+l;
	}
	for(i=0;i<primevec.size();i++){
		ll p=primevec[i];
		if(p>r) break;
		ll base = (l/primevec[i])*p;
		if(base<l) base+=p;
		for(j=base;j<=r;j+=p){
				etf[j-l]/=p;
				etf[j-l]*=(p-1);
			while(extraprime[j-l]%p==0){
				extraprime[j-l]/=p;
			}
		}
	}
	for(i=0;i<=(r-l);i++){
		if(extraprime[i]>1){
			etf[i]/=extraprime[i];
			etf[i]*=(extraprime[i]-1);
		}
	}
	for(i=0;i<=(r-l);i++){
		//cout<<"etf of "<<l+i<<" "<<etf[i]<<endl;
		if(etf[i]%k==0){
			c++;
		}
	}
	double ans = (double)c/(r-l+1);
	cout << fixed << setprecision(6) << ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	sieve();
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}












