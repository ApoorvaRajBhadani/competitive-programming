#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000000
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
struct cordinc{
	ll e=0,s=0;
};
void solve(){
	string s;
	cin>>s;
	s = "1(" + s + ")";
	ll x,y,i,j;
	stack<ll> paropenmul;
	stack<cordinc> perdepcordinc;
	cordinc currlevel = {0,0};
	perdepcordinc.push(currlevel);
	for(i=0;i<s.length();i++){
		if(s[i]>='1' && s[i]<='9'){
			paropenmul.push(s[i]-'0');
			cordinc thislevel = {0,0};
			perdepcordinc.push(thislevel);
			i++;
		}else if(s[i]==')'){
			ll mul = paropenmul.top();paropenmul.pop();
			currlevel = perdepcordinc.top();perdepcordinc.pop();
			currlevel.e = ((currlevel.e )*mul);
			currlevel.s = (((currlevel.s))*mul);
			cordinc lastlevel = perdepcordinc.top();perdepcordinc.pop();
			lastlevel.e = (lastlevel.e + currlevel.e + MOD)%MOD;
			lastlevel.s = (lastlevel.s + currlevel.s + MOD)%MOD;
			perdepcordinc.push(lastlevel);
		}else{
			currlevel = perdepcordinc.top();perdepcordinc.pop();
			if(s[i]=='N'){
				currlevel.s--;
			}else if(s[i]=='S'){
				currlevel.s++;
			}else if(s[i]=='W'){
				currlevel.e--;
			}else if(s[i]=='E'){
				currlevel.e++;
			}
			perdepcordinc.push(currlevel);
		}
	}
	cordinc lastlevel = perdepcordinc.top();
	x = 1+(MOD + lastlevel.e)%MOD;
	y = 1+(MOD + lastlevel.s)%MOD;
	cout<<x<<" "<<y<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}











