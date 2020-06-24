#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
void buildZ(ll* Z,string& s){
	ll l,r,n=s.size();
	l=r=0;
	for(ll i=1;i<n;i++){
		if(i>r){
			//Z doesn't exist already
			l=r=i;
			while(r<n&&s[r]==s[r-l]){
				r++;
			}
			Z[i]=r-l;
			r--;
		}else{
			//i is b/w l and r
			ll k=i-l;
			if(Z[k]+i<=r){
				Z[i]=Z[k];
			}else{
				l=i;
				while(r<n&&s[r-l]==s[r]){
					r++;
				}
				Z[i]=r-l;
				r--;
			}
		}
	}
}
int main(){
	string s;
	cin>>s;
	ll n=s.size();
	ll* Z=new ll[n]();
	buildZ(Z,s);
	for(auto ch:s) cout<<ch<<" ";
	cout<<endl;
	for(ll i=0;i<n;i++) cout<<Z[i]<<" ";
	cout<<endl;
	return 0;
}
