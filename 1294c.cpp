#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll; 


// Using SieveOfEratosthenes to find smallest prime 
// factor of all the numbers. 
// For example, if N is 10, 
// s[2] = s[4] = s[6] = s[10] = 2 
// s[3] = s[9] = 3 
// s[5] = 5 
// s[7] = 7 
void sieveOfEratosthenes(ll N,map<ll,ll> &s) 
{ 
	// Create a boolean array "prime[0..n]" and 
	// initialize all entries in it as false. 
	vector <bool> prime(N+1, false); 

	// Initializing smallest factor equal to 2 
	// for all the even numbers 
	for (ll i=2; i<=N; i+=2) 
		s[i] = 2; 

	// For odd numbers less then equal to n 
	for (ll i=3; i<=N; i+=2) 
	{ 
		if (prime[i] == false) 
		{ 
			// s(i) for a prime is the number itself 
			s[i] = i; 

			// For all multiples of current prime number 
			for (ll j=i; j*i<=N; j+=2) 
			{ 
				if (prime[i*j] == false) 
				{ 
					prime[i*j] = true; 

					// i is the smallest prime factor for 
					// number "i*j". 
					s[i*j] = i; 
				} 
			} 
		} 
	} 
} 

// Function to generate prime factors and its power 
void generatePrimeFactors(ll N) 
{ 
	// s[i] is going to store smallest prime factor 
	ll nn=N;
	// of i. 
	//ll s[N+1]; 
	map<ll,ll> s;

	// Filling values in s[] using sieve 
	sieveOfEratosthenes(N, s); 

	//printf("Factor Power\n"); 

	ll curr = s[N]; // Current prime factor of N 
	ll cnt = 1; // Power of current prime factor 

	// Printing prime factors and their powers 
	map<ll,ll> mp;
	while (N > 1) 
	{ 
		N /= s[N]; 

		// N is now N/s[N]. If new N als has smallest 
		// prime factor as curr, increment power 
		if (curr == s[N]) 
		{ 
			cnt++; 
			continue; 
		} 

		//printf("%d\t%d\n", curr, cnt); 
		mp[curr]=cnt;
		

		// Update current prime factor as s[N] and 
		// initializing count as 1. 
		curr = s[N]; 
		cnt = 1; 
	}
	if(mp.size()>=3){
		 cout<<"YES\n";
		 ll a,b,c;
		 map<ll,ll>::iterator it=mp.begin();
		 a=pow(it->first,it->second);
		 it++;
		 b=pow(it->first,it->second);
		 c = nn/(a*b);
		 
		 cout<<a<<" "<<b<<" "<<c<<endl;
	 }else if(mp.size()==2){
		 map<ll,ll>::iterator it=mp.begin();
		 ll b1,p1,b2,p2,pmax;
		 p1=it->second;
		 b1=it->first;
		 it++;
		 p2=it->second;
		 b2 = it->first;
		 pmax=max(p1,p2);
		 if(pmax>=3){
			 cout<<"YES\n";
			 if(p1<p2){
				 ll a = pow(b1,p1),b=pow(b2,p2-1);
				 cout<<a<<" "<<b2<<" "<<b<<endl;
			 }else{
				 ll a = pow(b2,p2),b=pow(b1,p1-1);
				 cout<<a<<" "<<b1<<" "<<b<<endl;
			 }
				 
		 }
		 else cout<<"NO\n";
	 }else if(mp.size()==1){
		 map<ll,ll>::iterator it=mp.begin();
		 if(it->second>=6){
			 cout<<"YES\n";
			 ll a,b,c;
			 a = it->first;
			 b= a*a;
			 c = pow(a,it->second-3);
			 cout<<a<<" "<<b<<" "<<c<<endl;
		 }
		 else cout<<"NO\n";
	 }else cout<<"NO\n";
}
int main(){
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		generatePrimeFactors(n);
	}
	return 0;
}
