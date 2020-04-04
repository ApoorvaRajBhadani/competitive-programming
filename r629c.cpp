#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,len;
	string a="",b="",x;
	cin>>n;
	cin>>x;
	len = x.length();
	bool pomg=false;
	for(i=0;i<len;i++){
		if(pomg){
			if(x[i]=='0'){
				a+='0';
				b+='0';
			}else if(x[i]=='2'){
				a+='0';
				b+='2';
			}
			else if(x[i]=='1'){
				a+='0';
				b+='1';
			}
		}else{
			if(x[i]=='0'){
				a+='0';
				b+='0';
			}else if(x[i]=='2'){
				a+='1';
				b+='1';
			}
			else if(x[i]=='1'){
				a+='1';
				b+='0';
				pomg=true;
			}
		}
	}
	cout<<a<<endl<<b<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
