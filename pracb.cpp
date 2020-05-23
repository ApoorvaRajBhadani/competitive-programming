#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	if(n%2==0){
		cout<<n+4<<" "<<4;
	}else{
		cout<<n+9<<" "<<9;
	}
	return 0;
}
