#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll; 
int main(){
	ll x,xs,i,x2;
	cin>>x;
	xs = sqrt(x);
	for(i=xs;i>=1;i--){
		x2 = x/i;
		if(__gcd(x2,i)==1 && x2*i==x) {cout<<min(i,x2)<<" "<<max(i,x2); break;
		}
	}
	return 0;
}
