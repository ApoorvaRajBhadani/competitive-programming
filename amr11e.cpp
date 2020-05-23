#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool isprime[1000001];
vector<ll> primes;
void sieve(){
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	ll i,j;
	for(i=2;i*i<=1000000;i++){
		if(isprime[i]){
			for(j=i*i;j<=1000000;j+=i){
				isprime[j]=false;
			}
		}
	}
	for(i=2;i<=1000000;i++) if(isprime[i]) primes.push_back(i);
}
void segsieve(){
	ll l=1000001,r=2000000,i,j;
	do{
	bool isprm[1000001];
	for(i=0;i<=(r-l);i++) isprm[i]=true;
	for(i=0;primes[i]*primes[i]<=r;i++){
		ll currprime=primes[i];
		ll base = (l/currprime)*currprime;
		if(base<l) base+=currprime;
		for(j=base;j<=r;j+=currprime){
			isprm[j-l]=false;
		}
		if(base==currprime) isprm[base-l]=true;
	}
	for(i=0;i<=r-l;i++) if(isprm[i]) primes.push_back(i+l);
	l+=1000000;r+=1000000;
	}while(l<=100000000);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	sieve();
	segsieve();
	//cout<<primes.size();
	while(true){
		ll n;
		cin>>n;
		if(n==0) break;
		auto it = upper_bound(primes.begin(),primes.end(),n);
		ll pi = it - primes.begin();
		//cout<<n<<"---"<<pi<<endl;
		double form = (double)(n)/log(n);
		double err = abs(pi-form)/pi;
		err*=100;
		cout << fixed << setprecision(1) << err<<endl; 
	}
	return 0;
}












