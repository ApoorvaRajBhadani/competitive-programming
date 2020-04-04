#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,spent=0,cur;
		cin>>n;
		while(n>=10){
			cur = (n/10);
			spent += (cur*10);
			n-= (cur*10);
			n+= cur;
		}
		spent += n;
		cout<<spent<<endl;
	}
	return 0;
}
