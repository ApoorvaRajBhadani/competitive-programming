#include<bits/stdc++.h> 
#include<climits> 
using namespace std;
typedef long long int ll;
int main(){
	ll t,n,d;
	cin>>t;
	while(t--){
		cin>>n;
		string s="";
		if(n%2==1){
			s+='7';
			n-=3;
		}
		while(n>0){
			s+='1';
			n-=2;
		}
		cout<<s<<endl;
	}
	return 0;
}
