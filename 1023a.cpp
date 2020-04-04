#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	int n;
	cin>>n;
	if((n-2)%3==0){
		cout<<1<<" "<<2<<" "<<n-3;
	}else cout<<1<<" "<<1<<" "<<n-2;
return 0;
}
