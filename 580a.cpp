#include<bits/stdc++.h> 
#include<climits> 
using namespace std;
typedef long long int ll;

int main(){
	int n;
	cin>>n;
	int t,i,p,c=1,mx=0;
	cin>>p;
	for(i=1;i<n;i++){
		cin>>t;
		if(p<=t) c++;
		else{
			mx = max(mx,c);
			c=1;
		}
		p = t;
		//cout<<c<<"-"<<mx<<" ";
	}
	mx = max(mx,c);
	cout<<mx;
	return 0;
}
