#include<bits/stdc++.h> 
using namespace std;
typedef unsigned long long int ll;
#define MOD 998244353
#define endl '\n' 
struct expans{
	long long int f0=0,f1=0,f2=0,f3=0;
};
expans hashans = {748683265,748683265,748683265,748683265};
int resultand[16] = {0,0,0,0,0,1,2,3,0,2,2,0,0,3,0,3};
int resultor[16]  = {0,1,2,3,1,1,1,1,2,1,2,1,3,1,1,3};
int resultxor[16] = {0,1,2,3,1,0,3,2,2,3,0,1,3,2,1,0};
map<pair<ll,ll>,expans> mpexpans;
expans findexpans(ll left,ll right){
	if(left==right) return hashans;
	return mpexpans[make_pair(left,right)];
}
void computeexpans(ll openparidx,ll closeparidx,ll optridx,char optrtype){
	ll i,j,k;
	expans curans={0,0,0,0};
	expans lopans=findexpans(openparidx+1,optridx-1);
	expans ropans=findexpans(optridx+1,closeparidx-1);
	//cout<<lopans.f0<<" "<<lopans.f1<<" "<<lopans.f2<<" "<<lopans.f3<<endl;
	//cout<<ropans.f0<<" "<<ropans.f1<<" "<<ropans.f2<<" "<<ropans.f3<<endl;
	ll anstoadd[16];
	for(i=0,k=0;i<4;i++){
		ll lopanss;
		if(i==0){
			lopanss=lopans.f0;
		}else if(i==1){
			lopanss=lopans.f1;
		}else if(i==2){
			lopanss=lopans.f2;
		}else if(i==3){
			lopanss=lopans.f3;
		}
		for(j=0;j<4;j++){
			ll ropanss;
			if(j==0){
				ropanss=ropans.f0;
			}else if(j==1){
				ropanss=ropans.f1;
			}else if(j==2){
				ropanss=ropans.f2;
			}else if(j==3){
				ropanss=ropans.f3;
			}
			anstoadd[k]=((lopanss%MOD)*(ropanss%MOD))%MOD;
			//cout<<anstoadd[k]<<"ie  "<<lopanss<<"*"<<ropanss<<endl;
			k++;
		}
	}
	if(optrtype=='&'){
		for(i=0;i<16;i++){
			if(resultand[i]==0){
				curans.f0= ((curans.f0%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultand[i]==1){
				curans.f1= ((curans.f1%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultand[i]==2){
				curans.f2= ((curans.f2%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultand[i]==3){
				curans.f3= ((curans.f3%MOD) + (anstoadd[i]%MOD))%MOD;
			}
		}
	}else if(optrtype=='|'){
		for(i=0;i<16;i++){
			if(resultor[i]==0){
				curans.f0= ((curans.f0%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultor[i]==1){
				curans.f1= ((curans.f1%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultor[i]==2){
				curans.f2= ((curans.f2%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultor[i]==3){
				curans.f3= ((curans.f3%MOD) + (anstoadd[i]%MOD))%MOD;
			}
		}
	}else if(optrtype=='^'){
		for(i=0;i<16;i++){
			if(resultxor[i]==0){
				curans.f0= ((curans.f0%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultxor[i]==1){
				curans.f1= ((curans.f1%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultxor[i]==2){
				curans.f2= ((curans.f2%MOD) + (anstoadd[i]%MOD))%MOD;
			}else if(resultxor[i]==3){
				curans.f3= ((curans.f3%MOD) + (anstoadd[i]%MOD))%MOD;
			}
		}
	}
	mpexpans[make_pair(openparidx,closeparidx)]=curans;
}
void solve(){
	string s;
	cin>>s;
	ll i,len=s.length();
	mpexpans.clear();
	stack<ll> parst,optrst;
	stack<char> optrtypest;
	for(i=0;i<len;i++){
		if(s[i]=='('){
			parst.push(i);
		}else if(s[i]==')'){
			ll closeparidx=i;
			ll openparidx = parst.top();parst.pop();
			ll optridx = optrst.top();optrst.pop();
			char optrtype = optrtypest.top();optrtypest.pop();
			computeexpans(openparidx,closeparidx,optridx,optrtype);
		}else if(s[i]=='#'){
			//hash mila hehehehehehe
		}else{
			optrst.push(i);
			optrtypest.push(s[i]);
		}
	}
	expans ans=findexpans(0,len-1);
	cout<<ans.f0<<" "<<ans.f1<<" "<<ans.f2<<" "<<ans.f3<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
