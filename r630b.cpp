#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
vector<int> primes;
void simpleSieve(int limit, vector<int>& prime) 
{ 
    bool mark[limit + 1]; 
    memset(mark, false, sizeof(mark)); 
  
    for (int i = 2; i <= limit; ++i) { 
        if (mark[i] == false) { 
            // If not marked yet, then its a prime 
            prime.push_back(i); 
            for (int j = i; j <= limit; j += i) 
                mark[j] = true; 
        } 
    } 
} 
  
// Finds all prime numbers in given range using 
// segmented sieve 
void primesInRange(int low, int high) 
{ 
    // Comput all primes smaller or equal to 
    // square root of high using simple sieve 
    int limit = floor(sqrt(high)) + 1; 
    vector<int> prime; 
    simpleSieve(limit, prime); 
  
    // Count of elements in given range 
    int n = high - low + 1; 
  
    // Declaring boolean only for [low, high] 
    bool mark[n + 1]; 
    memset(mark, false, sizeof(mark)); 
  
    // Use the found primes by simpleSieve() to find 
    // primes in given range 
    for (int i = 0; i < prime.size(); i++) { 
        // Find the minimum number in [low..high] that is 
        // a multiple of prime[i] (divisible by prime[i]) 
        int loLim = floor(low / prime[i]) * prime[i]; 
        if (loLim < low) 
            loLim += prime[i]; 
        if(loLim==prime[i]) 
            loLim += prime[i]; 
        /*  Mark multiples of prime[i] in [low..high]: 
            We are marking j - low for j, i.e. each number 
            in range [low, high] is mapped to [0, high - low] 
            so if range is [50, 100]  marking 50 corresponds 
            to marking 0, marking 51 corresponds to 1 and 
            so on. In this way we need to allocate space only 
            for range  */
        for (int j = loLim; j <= high; j += prime[i]) 
            mark[j - low] = true; 
    } 
  
    // Numbers which are not marked in range, are prime 
    for (int i = low; i <= high; i++) 
        if (!mark[i - low]) {
            primes.push_back(i);
            //cout<<i<<endl;
		}
} 
ll topparent(ll* parent,ll child){
	while(parent[child]!=-1){
		child = parent[child];
	}
	return child;
}
ll uniteparent(ll* parent,ll s,ll d){
	ll stp,dtp;
	stp = topparent(parent,s);
	dtp = topparent(parent,d);
	if(stp!=dtp){
		parent[dtp] = stp;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t,i,j;
	cin>>t;
	primesInRange(2,1000);
	//cout<<primes.size();
	while(t--){
		ll n;
		cin>>n;
		int* arr = new int[n];
		for(i=0;i<n;i++) cin>>arr[i];
		bool used[n];
		for(i=0;i<n;i++) used[i]=false;
		map<ll,vector<ll>> mp;
		for(i=0;i<primes.size();i++){
				for(j=0;j<n;j++){
					//cout<<primes[i]<<endl;
					if(arr[j]%primes[i] == 0 && !used[j]) {
						mp[primes[i]].push_back(j);
						//cout<<primes[i]<<" "<<j<<endl;
						used[j]=1;
					}
				}
				//cout<<endl;
			
		}
		
		ll* parent = new ll[n];
		for(i=0;i<n;i++) parent[i] = -1;
		
		for(auto it = mp.begin();it!=mp.end();it++){
			vector<ll> vec = it->second;
			//cout<<it->first<<endl;
			for(i =0;i<vec.size()-1;i++){
				if(topparent(parent,vec[i])!=topparent(parent,vec[i+1])){
					uniteparent(parent,vec[i],vec[i+1]);
				}
			}
		}
		
		ll m=0,nam=1;
		map<ll,ll> parname;
		for(i=0;i<n;i++) {
			if(parent[i]==-1) {
				m++;
				parname[i] = nam;
				nam++;
			}
		}
		cout<<m<<endl;
		for(i=0;i<n;i++){
			cout<<parname[topparent(parent,i)]<<" ";
		}
		cout<<endl;
	}
	return 0;
}




















