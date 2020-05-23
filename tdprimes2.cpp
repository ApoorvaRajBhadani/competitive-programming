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
ll isprime2[100000001];
vector<ll> primes2;
void segsieve(){
	ll l=0,r=100000000,i,j;
	for(i=0;i<=(100000000);i++) isprime2[i]=true;
	isprime2[0]=isprime2[1]=false;
	for(i=0;primes[i]*primes[i]<=100000000;i++){
		ll p = primes[i];
		ll base = p;
		for(j=base;j<=100000000;j+=p){
			isprime2[j]=false;
		}
		if(base==p) isprime2[base]=true;
	}
	for(i=2;i<=(100000000);i++){
		if(isprime2[i]) {
			primes2.push_back(i);
			//if(i<=100) cout<<i<<" ";
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	sieve();
	segsieve();
	//for(ll i=0;i<=100;i++) cout<<primes2[i]<<endl;
	for(ll i=0;i<primes2.size();i+=100){
		cout<<primes2[i]<<endl;
		//if(i>=10000) break;
	}
	return 0;
}
















