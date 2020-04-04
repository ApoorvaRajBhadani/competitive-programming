#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

// Function to find the nCr 
ll printNcR(ll n, ll r) 
{ 
  
    // p holds the value of n*(n-1)*(n-2)..., 
    // k holds the value of r*(r-1)... 
    ll p = 1, k = 1; 
  
    // C(n, r) == C(n, n-r), 
    // choosing the smaller value 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
  
            // gcd of p, k 
            ll m = __gcd(p, k); 
  
            // dividing by gcd, to simplify product 
            // division by their gcd saves from the overflow 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
  
        // k should be simplified to 1 
        // as C(n, r) is a natural number 
        // (denominator should be 1 ) . 
    } 
  
    else
        p = 1; 
  
    // if our approach is correct p = ans and k =1 
    //cout << p << endl;
    return p; 
} 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,i,nz=0,np=0,nn=0,a,b,t,c=0;
	vector<ll> pos,neg;
	cin>>n;
	ll arra[n],arrb[n];
	for(i=0;i<n;i++)
		cin>>arra[i];
	for(i=0;i<n;i++){
		cin>>arrb[i];
		t = arra[i]-arrb[i];
		if(t>0){
			np++;
			pos.push_back(t);
		}else if(t<0){
			neg.push_back(t*-1);
			nn++;
		}else{
			nz++;
		}
	}
	c = np*nz;
	if(np>=2) c+=printNcR(np,2);
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	int i1,i2=0;
	for(i1=0;i1<np;i1++){
		//cout<<pos[i1]<<endl;
		while(pos[i1] - neg[i2] >0 && i2<nn){
			c+= (np-i1);
			i2++;
		}
	}
	cout<<c;
	
	return 0;
}
