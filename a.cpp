#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	int q;
	cin>>q;
	while(q--){
	int n,t,c=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t%2==1) c++;
	}
	if((c<n&&c>=1) || (c==n&&n%2==1)) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
	}
	return 0;
}
