#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll power(ll x,ll y,ll m){            //power(x,y)=x^y  %m;
	if(y==0)return 1;
	ll a=power(x,y/2,m);
	if(y%2){
		return (a*((a*x)%m))%m;
	}
	else{
		return (a*a)%m;
	}
}
ll mod_inverse(ll x,ll m){
	return power(x,m-2,m);
}
ll fact(ll n,ll m){
	if(n<=1)return 1;
	return (fact(n-1,m)*n)%m;
}
ll ncr(ll n,ll r,ll m){
	if(r>n)return 0;
	ll n1=1,d1=1,d2=1;
	n1=fact(n,m);d1=fact(r,m);d2=fact(n-r,m);
	ll ans=mod_inverse((d1*d2)%m,m);
	ans=(ans*n1)%m;
	return ans;
}
int ispal(string s){
	int len=s.size();
	int flag=1;
	for(int i=0;i<len;++i){
		if(s[i]!=s[len-i-1]){
			flag=0;break;
		}
	}
	return flag;
}
int mmt[6][2]={{-1,-1}, {-1,0}, {0,-1}, {0,1}, {1,0}, {1,1}};
void solve(){
	ll n,i,pr,pk,r,k,val;
	cin>>n;
	map<pair<int,int>,bool> mp;
	vector<int> vecr,veck;
	mp[make_pair(1,1)]=true;
	vecr.push_back(1);
	veck.push_back(1);
	n-=1;
	//cout<<1<<endl;
	pr=pk=0;
	while(n>0){
		cout<<n<<endl;
		ll mx=0,usedr,usedk;
		for(i=0;i<6;i++){
			r = pr + mmt[i][0];
			k = pk + mmt[i][1];
			if(r>=0 && k>=0 &&k<=r&&!mp[make_pair(r,k)]){
				val = ncr(r,k,MOD);
				if(val<=n){
					if(val>=mx){
						usedr = r;
						usedk=k;
						mx=val;
					}
				}
			}
		}
		n-=mx;
		//cout<<mx<<endl;
		vecr.push_back(usedr+1);
		veck.push_back(usedk+1);
		mp[make_pair(usedr,usedk)]=true;
		pk = usedk;
		pr = usedr;
		if(vecr.size()==15) break;
	}
	for(i=0;i<vecr.size();i++){
		cout<<vecr[i]<<" "<<veck[i]<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<":\n";
		solve();
	}
	return 0;
}
