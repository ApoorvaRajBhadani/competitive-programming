#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define MAX 100000
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
vector<ll>* findprimes(){
	ll i,j;
	bool primes[MAX+1];
	for(i=2;i<=MAX;i++) primes[i]=true;
	for(i=2;i*i<=MAX;i++){
		if(primes[i]){
			for(j=i*i;j<=MAX;j+=i){
				primes[j]=false;
			}
		}
	}
	vector<ll>* prime = new vector<ll>;
	prime->push_back(2);
	for(i=3;i<=MAX;i+=2){
		if(primes[i]) {
			prime->push_back(i);
		}
	}
	return prime;
}
void printprimes(ll l,ll r,vector<ll>* & primes){
	bool arr[r-l+1];
	ll i,j;
	for(i=0;i<=r-l;i++) arr[i]=true;
	for(i=0;primes->at(i) * primes->at(i) <=r;i++){
		ll currprime = primes->at(i);
		ll base = (l/currprime)*currprime;
		if(base<l) base+=currprime;
		for(j=base;j<=r;j+=currprime){
			arr[j-l]=false;
		}
		if(currprime == base){
			arr[base-l]=true;
		}
	}
	for(i=0;i<=(r-l);i++){
		if(arr[i]){
			cout<<l+i<<endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	vector<ll>* primes = findprimes();
	while(t--){
		ll l,r;
		cin>>l>>r;
		printprimes(l,r,primes);
	}
	return 0;
}












