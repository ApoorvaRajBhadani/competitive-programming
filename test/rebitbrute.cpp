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
char logicalExpressionEvaluation(string str) 
{ 
    stack<char> arr; 
    for (int i = str.length() - 1; i >= 0; i--)  
    { 
        if (str[i] == '(')  
        { 
            vector<char> s; 
            while (arr.top() != ')') 
            { 
                s.push_back(arr.top()); 
                arr.pop(); 
            } 
            arr.pop(); 
            if (s.size() == 3) 
            { 
                s[2] == '1' ? arr.push('0') : arr.push('1'); 
            } 
            else if (s.size() == 5) 
            { 
                int a = s[0] - 48, b = s[4] - 48, c; 
                //s[2] == '&' ? c = a & b : c = a | b;
                if(s[2]=='&') c=a&b;
                else if(s[2]=='|') c=a|b;
                else if(s[2]=='^') c=a^b; 
                arr.push((char)c + 48); 
            } 
        } 
        else
        { 
            arr.push(str[i]); 
        } 
    } 
    return arr.top(); 
}
string s;
char inp[4]={'0','1','a','A'};
vector<int> g0ans,g1ans;
void find(string str,ll starti,vector<string>& exps){
	ll i,j;
	for(i=starti;i<s.length();i++){
		if(s[i]=='#'){
			for(j=0;j<4;j++){
				string newstr=str+s.substr(starti,i-starti)+inp[j];
				find(newstr,i+1,exps);
			}
			return;
		}
	}
	string ns = str + s.substr(starti,s.length()-starti);
	exps.push_back(ns);
	//cout<<ns<<endl;
}
void computeg0(string s){
	string l="";
	for(ll i=0;i<s.length();i++){
		if(s[i]=='a') l+='0';
		else if(s[i]=='A') l+='1';
		else if(s[i]=='&' || s[i]=='|' || s[i]=='^') { l+=',';l+=s[i];l+=',';}
		else l+=s[i];
	}
	//cout<<l<<"   ";
	//cout<<logicalExpressionEvaluation(l)<<endl;
	g0ans.push_back(logicalExpressionEvaluation(l) - '0');
}
void computeg1(string s){
	string l="";
	for(ll i=0;i<s.length();i++){
		if(s[i]=='a') l+='1';
		else if(s[i]=='A') l+='0';
		else if(s[i]=='&' || s[i]=='|' || s[i]=='^') { l+=',';l+=s[i];l+=',';}
		else l+=s[i];
	}
	//cout<<l<<"   ";
	//cout<<logicalExpressionEvaluation(l)<<endl;
	g1ans.push_back(logicalExpressionEvaluation(l) - '0');
}
int solve(){
	s="";
	g0ans.clear();g1ans.clear();
	cin>>s;
	ll i,len = s.length();
	vector<ll> hashidx;
	for(i=0;i<len;i++){
		if(s[i]=='#') hashidx.push_back(i);
	}
	vector<string> exps;
	string pppp="";
	find(pppp,0,exps);
	cout<<exps.size()<<endl;
	for(auto it=exps.begin();it!=exps.end();it++){
		//cout<<*it<<endl;
		computeg0(*it);
		computeg1(*it);
	}
	ll p0=0,p1=0,pa=0,pA=0;
	for(i=0;i<exps.size();i++){
		if(g0ans[i]==0 && g1ans[i]==0) p0++;
		else if(g0ans[i]==1 && g1ans[i]==1) p1++;
		else if(g0ans[i]==0 && g1ans[i]==1) pa++;
		else if(g0ans[i]==1 && g1ans[i]==0) pA++;
	}
	ll den = pow(4,hashidx.size());
	cout<<p0<<"/"<<den<<" "<<
			p1<<"/"<<den<<" "<<
			pa<<"/"<<den<<" "<<
			pA<<"/"<<den<<endl;
	ll probans=0;
	den = pow(4,hashidx.size());lowest(den,p0);
	probans = (p0*modInverse(den,MOD))%MOD;
	cout<<probans<<" ";
	den = pow(4,hashidx.size());lowest(den,p1);
	probans = (p1*modInverse(den,MOD))%MOD;
	cout<<probans<<" ";
	den = pow(4,hashidx.size());lowest(den,pa);
	probans = (pa*modInverse(den,MOD))%MOD;
	cout<<probans<<" ";
	den = pow(4,hashidx.size());lowest(den,pA);
	probans = (pA*modInverse(den,MOD))%MOD;
	cout<<probans<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
