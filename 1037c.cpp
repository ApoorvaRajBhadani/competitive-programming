#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,t,c=0;
	cin>>n;
	string a,b;
	cin>>a>>b;
	for(i=0;i<n;i++){
		if(a[i]==b[i]) continue;
		else{
			if((a[i+1]!=b[i+1])&&(a[i]!=a[i+1]) && (i<n-1)){
				c++;
				i++;
			}
			else c++;
		}
	}
	cout<<c;
	return 0;
}
