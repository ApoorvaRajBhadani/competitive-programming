#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 998244353
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll gcd(ll a, ll b); 
ll power(ll x, unsigned long long int y, unsigned long long int m); 
ll modInverse(ll a, ll m) 
{ 
    int g = gcd(a, m); 
    if (g != 1) 
        return -1; 
    else
    { 
             return power(a, m-2, m); 
    } 
}
ll power(ll x, unsigned long long int y, unsigned long long int m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
}
ll gcd(ll a, ll b) 
{
	return __gcd(a,b);
    //if (a == 0) 
        //return b; 
    //return gcd(b%a, a); 
}
ll lcm(ll a, ll b)  
{  
    return (a*b)/gcd(a, b);  
}
void lowest(ll &den3, ll &num3) 
{ 
    ll common_factor = gcd(num3,den3);  
    den3 = den3/common_factor; 
    num3 = num3/common_factor; 
}
void addFraction(ll num1, ll den1, ll num2,  ll den2, ll &num3, ll &den3) 
{  
    den3 = gcd(den1,den2); 
    den3 = (den1*den2) / den3; 
    num3 = (num1)*(den3/den1) + (num2)*(den3/den2); 
    lowest(den3,num3); 
} 
struct expans{
	ll n0=0,n1=0,n2=0,n3=0;
	ll d0=1,d1=1,d2=1,d3=1;
};
expans hashans = {1,1,1,1,4,4,4,4};
int resultand[16] = {0,0,0,0,0,1,2,3,0,2,2,0,0,3,0,3};
int resultor[16] = {0,1,2,3,1,1,1,1,2,1,2,1,3,1,1,3};
int resultxor[16] = {0,1,2,3,1,0,3,2,2,3,0,1,3,2,1,0};
map<pair<ll,ll>,expans> mpexpans;
expans findexpans(ll left,ll right){
	if(left==right) return hashans;
		return mpexpans[make_pair(left,right)];
}
void computeexpans(ll openparidx,ll closeparidx,ll optridx,char optrtype){
	ll i,j,k;
	expans curans={0,0,0,0,1,1,1,1};
	expans lopans=findexpans(openparidx+1,optridx-1);
	expans ropans=findexpans(optridx+1,closeparidx-1);
	ll anstoaddn[16],anstoaddd[16];
	for(i=0,k=0;i<4;i++){
		ll lopanssn,lopanssd;
		if(i==0){
			lopanssn=lopans.n0;
			lopanssd=lopans.d0;
		}else if(i==1){
			lopanssn=lopans.n1;
			lopanssd=lopans.d1;
		}else if(i==2){
			lopanssn=lopans.n2;
			lopanssd=lopans.d2;
		}else if(i==3){
			lopanssn=lopans.n3;
			lopanssd=lopans.d3;
		}
		for(j=0;j<4;j++){
			ll ropanssn,ropanssd;
			if(i==0){
				ropanssn=ropans.n0;
				ropanssd=ropans.d0;
			}else if(i==1){
				ropanssn=ropans.n1;
				ropanssd=ropans.d1;
			}else if(i==2){
				ropanssn=ropans.n2;
				ropanssd=ropans.d2;
			}else if(i==3){
				ropanssn=ropans.n3;
				ropanssd=ropans.d3;
			}
			anstoaddn[k]=lopanssn*ropanssn;
			anstoaddd[k]=lopanssd*ropanssd;
			lowest(anstoaddd[k],anstoaddn[k]);
			k++;
		}
	}
	ll aaa,bbb,ccc,ddd,ggg;
	if(optrtype=='&'){
		for(i=0;i<16;i++){
			if(resultand[i]==0){
				addFraction(curans.n0,curans.d0,anstoaddn[i],anstoaddd[i]
				,curans.n0,curans.d0);
			}else if(resultand[i]==1){
				addFraction(curans.n1,curans.d1,anstoaddn[i],anstoaddd[i]
				,curans.n1,curans.d1);
			}else if(resultand[i]==2){
				addFraction(curans.n2,curans.d2,anstoaddn[i],anstoaddd[i]
				,curans.n2,curans.d2);
			}else if(resultand[i]==3){
				addFraction(curans.n3,curans.d3,anstoaddn[i],anstoaddd[i]
				,curans.n3,curans.d3);
			}
		}
	}else if(optrtype=='|'){
		for(i=0;i<16;i++){
			if(resultor[i]==0){
				addFraction(curans.n0,curans.d0,anstoaddn[i],anstoaddd[i]
				,curans.n0,curans.d0);
			}else if(resultor[i]==1){
				addFraction(curans.n1,curans.d1,anstoaddn[i],anstoaddd[i]
				,curans.n1,curans.d1);
			}else if(resultor[i]==2){
				addFraction(curans.n2,curans.d2,anstoaddn[i],anstoaddd[i]
				,curans.n2,curans.d2);
			}else if(resultor[i]==3){
				addFraction(curans.n3,curans.d3,anstoaddn[i],anstoaddd[i]
				,curans.n3,curans.d3);
			}
		}
	}else if(optrtype=='^'){
		for(i=0;i<16;i++){
			if(resultxor[i]==0){
				addFraction(curans.n0,curans.d0,anstoaddn[i],anstoaddd[i]
				,curans.n0,curans.d0);
			}else if(resultxor[i]==1){
				addFraction(curans.n1,curans.d1,anstoaddn[i],anstoaddd[i]
				,curans.n1,curans.d1);
			}else if(resultxor[i]==2){
				addFraction(curans.n2,curans.d2,anstoaddn[i],anstoaddd[i]
				,curans.n2,curans.d2);
			}else if(resultxor[i]==3){
				addFraction(curans.n3,curans.d3,anstoaddn[i],anstoaddd[i]
				,curans.n3,curans.d3);
			}
		}
	}
	mpexpans[make_pair(openparidx,closeparidx)]=curans;
}
void solve(){
	string s;
	cin>>s;
	ll i,len=s.length(),hashes=0,den;
	mpexpans.clear();
	//mpansexists.clear();
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
			//cout<<"# mila hahahaha\n";
			//hashes++;
		}else{
			optrst.push(i);
			optrtypest.push(s[i]);
		}
	}
	expans ans=findexpans(0,len-1);
	cout<<ans.n0<<"/"<<ans.d0<<" "<<
			ans.n1<<"/"<<ans.d1<<" "<<
			ans.n2<<"/"<<ans.d2<<" "<<
			ans.n3<<"/"<<ans.d3<<endl;
	ll probans=0;
	probans = (ans.n0*modInverse(ans.d0,MOD))%MOD;
	cout<<probans<<" ";
	probans = (ans.n1*modInverse(ans.d1,MOD))%MOD;
	cout<<probans<<" ";
	probans = (ans.n2*modInverse(ans.d2,MOD))%MOD;
	cout<<probans<<" ";
	probans = (ans.n3*modInverse(ans.d3,MOD))%MOD;
	cout<<probans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
//((((((((((((((((((((((((((((((((((((((((#^#)^#)|#)^#)^#)^#)^#)^#)^#)^#)&#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)^#)
