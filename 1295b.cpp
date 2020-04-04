#include<bits/stdc++.h> 
#include<climits> 
using namespace std;
typedef long long int ll;
int main(){
	int t;
	string s;
	ll n,x,i,j,n0,n1,frm,ass,pss,p0,p1,k,c;
	cin>>t;
	while(t--){
		cin>>n>>x>>s;
		n0=n1=0;
		p0=p1=0;
		ass = pss =0;
		c=0;k=0;
		for(i=0,j=n-1;i<n;i++,j--){
			if(s[i]=='0') n0++;
			else n1++;
			if(n0==n1) ass++;
			if(n0-n1 == x) k++;
			if(s[j]=='0') p0++;
			else p1++;
			if(p0==p1) pss++;
		}
		frm = n0 -n1;
		if(x==0){
			if(frm == 0) {
				//infinite times
				c=-1;
			}else{
				string ss = s+s;
				for(i=0;i<2*n;i++){
			if(s[i]=='0') n0++;
			else n1++;
			if(n0==n1) ass++;
			if(n0-n1 == x) k++;
		}
				c=k+1;
			}
		}
		else{
			// same sign
			if(frm>0){
			if(x/frm >0){
				if(x<0) x=-1*x;
				if(frm<0) frm = -1*frm;
				if(x%frm == 0){
					// yep possible at some point
					c=1;
					c+= ass;
					c+= pss;
				}else{
					string ss = s+s;
				for(i=0;i<2*n;i++){
			if(s[i]=='0') n0++;
			else n1++;
			if(n0==n1) ass++;
			if(n0-n1 == x) k++;
		}
				c=k;
				}
			}else{
				string ss = s+s;
				for(i=0;i<2*n;i++){
			if(s[i]=='0') n0++;
			else n1++;
			if(n0==n1) ass++;
			if(n0-n1 == x) k++;
		}
				c=k;
			}
			}
			else{
				string ss = s+s;
				for(i=0;i<2*n;i++){
			if(s[i]=='0') n0++;
			else n1++;
			if(n0==n1) ass++;
			if(n0-n1 == x) k++;
		}
				c=k;
			}
		
		}
		cout<<c<<endl;
	}
	return 0;
}
