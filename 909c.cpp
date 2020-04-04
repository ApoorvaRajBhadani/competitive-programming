#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll n,c=0;
void helper(char* s,ll n,ll idt,bool isreq){
	if(s[0]=='\0') {
		c = (c+1)%MOD;
		return;
	}
	if(isreq){
		idt++;
		if(s[0]=='f'){
			helper(s+1,idt,true);
		}
		else{
			helper(s+1,idt,false);
		}
	}else{
		for(ll i=0;i<=idt;i++){
			if(s[0]=='f'){
				helper(s+1,idt,true);
			}
			else{
				helper(s+1,idt,false);
			}
		}
	}
}
	
int main(){
	cin>>n;
	char ch;
	char s[5001];
	ll i,ans;
	for(i=0;i<n;i++){
		cin>>s[i];
	}for(;i<=5000;i++) s[i]='\0';
	helper(s,n,0,false);
	cout<<c;
	return 0;
}
