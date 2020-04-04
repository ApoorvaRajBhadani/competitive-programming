#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a==b){
			cout<<"0"<<endl;
		}if((b-a)>0){
			if((b-a) % 2 == 0) cout<<2<<endl;
			else cout<<1<<endl;
		}if(a-b>0){
			if((a-b) % 2 == 0) cout<<1<<endl;
			else cout<<2<<endl;
		}
	}
	return 0;
}
