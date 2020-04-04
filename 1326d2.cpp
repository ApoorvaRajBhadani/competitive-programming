#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void buildZ(int* Z,string str){
	int l,r,n,i;
	l=r=0;n=str.length();
	for(i=1;i<n;i++){
		if(i>r){
			l=r=i;
			while(r<n && str[r-l]==str[r]) r++;
			Z[i]=r-l;
			r--;
		}else{
			int k=i-l;
			if(Z[k]+i<=r){
				Z[i]=Z[k];
			}else{
				l=i;
				while(r<n && str[r-l]==str[r]) r++;
				Z[i] = r-l;
				r--;
			}
		}
	}
}
string longestPalSubstr(string a) 
{ 
	string b = a;
	reverse(b.begin(),b.end());
	string strab = a+"$"+b;
	int i,n = strab.length();
	int* Zab = new int[n]();
	buildZ(Zab,strab);
	int mxab=0;
	for(i=0;i<n;i++) {
		cout<<Zab[i]<<" ";
		mxab=max(mxab,Zab[i]);
	}
	cout<<endl;
	string strba = b+"$"+a;
	int* Zba = new int[n]();
	buildZ(Zba,strba);
	int mxba=0;
	for(i=0;i<n;i++) {
		cout<<Zba[i]<<" ";
		mxba = max(mxba,Zba[i]);
	}cout<<endl;
	if(mxab>mxba){
		return strab.substr(0,mxab);
	}
	return strba.substr(0,mxba);
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	string input[t];
	for(ll i=0;i<t;i++) cin>>input[i];
	for(ll iii=1;iii<=t;iii++){
		string s,a="",b="";
		s=input[iii-1];
		ll len = s.length();
		ll i=0,j=len-1;
		while(s[i]==s[j] && i<j){
			a = a+s[i];
			b = s[j]+b;
			i++;
			j--;
		}
		//cout<<i<<" "<<j<<endl;
		string fff = s.substr(i,j-i+1);
		cout<<a;
		string ans=longestPalSubstr(fff);
		cout<<ans;
		cout<<b<<endl;
	}
	return 0;
}
