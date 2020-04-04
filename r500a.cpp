#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	int p,q;
	cin>>p>>q;
	string a,b;
	cin>>a>>b;
	size_t wcpos = a.find("*");
	if(a[0]=='*'){
		size_t ans = b.find(a[1]);
		if(ans!=string::npos) cout<<"YES";
		else cout<<"NO";
	}else if(a[p-1]=='*'){
		string newa = a.substr(0,p-1);
		size_t ans = b.find(newa);
		if(ans!=string::npos) cout<<"YES";
		else cout<<"NO";
	}
	else if(wcpos!= string::npos){
		string pl,pr;
		pl = a.substr(0,wcpos);
		pr = a.substr(wcpos+1,a.size()-wcpos-1);
		size_t plinbpos = b.find(pl);
		size_t prinbpos = b.find(pr,plinbpos + pl.size());
		if(prinbpos!=string::npos){
			cout<<"YES";
		}
		else cout<<"NO";
	}
	else{
		size_t ans = b.find(a);
		if(ans!=string::npos) cout<<"YES";
		else cout<<"NO";
	} 
return 0;
}
