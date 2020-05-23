#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool isprime[1000001];
vector<ll> primes;
void sieve(){
	ll i,j;
	for(i=2;i<=1000000;i++) isprime[i]=true;
	isprime[0]=isprime[1]=false;
	for(i=2;i*i<=1000000;i++){
		if(isprime[i]){
			for(j=i*i;j<=1000000;j+=i){
				isprime[j]=false;
			}
		}
	}
	primes.push_back(2);
	for(i=3;i<=1000000;i+=2) if(isprime[i]) primes.push_back(i);
}
void segsieve(){
	ll l=1000001,r=2*1000000,i,j;
	do{
	for(i=0;i<=(r-l);i++) isprime[i]=true;
	for(i=0;primes[i]*primes[i]<=r;i++){
		ll p = primes[i];
		ll base = (l/p)*p;
		if(base<l) base+=p;
		for(j=base;j<=r;j+=p){
			isprime[j-l]=false;
		}
		if(base==p) isprime[base-l]=true;
	}
	for(i=0;i<=(r-l);i++){
		if(isprime[i]) primes.push_back(i+l);
	}
	l+=1000000;
	r+=1000000;
	}while(l<=99*1000000+1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	sieve();
	segsieve();
	for(ll i=0;i<primes.size();i+=100){
		cout<<primes[i]<<endl;
		//if(i>=10000) break;
	}
	return 0;
}
















