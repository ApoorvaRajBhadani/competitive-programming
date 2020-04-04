#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,p=0,q=1,ans=q,i;
	cin>>n;
	cout<<ans<<" ";
	for(i=2;i<=n;i++){
		ans = p+q;
		cout<<ans<<" ";
		p=q;
		q=ans;
	}
	//cout<<ans;
	return 0;
}
