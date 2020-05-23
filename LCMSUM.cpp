#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll etf[1000001];
ll spf[1000001];
void sieve(){
	ll i,j;
	for(i=0;i<=1000000;i++) {etf[i]=i;spf[i]=i;}
	for(i=2;i<=1000000;i++){
		if(etf[i]==i){
			for(j=i;j<=1000000;j+=i){
				etf[j]/=i;
				etf[j]*=(i-1);
				if(spf[j]==j)spf[j]=i;
			}
		}
	}
}
void primefacto(ll n,vector<pair<ll,ll>>& vec){
	ll lastprime = 1,k=0;
	while(n>1){
		if(lastprime!=spf[n])vec.push_back(make_pair(spf[n],0));
		vec[vec.size()-1].second++;
		lastprime=spf[n];
		n/=spf[n];
	}
}
void divisors(vector<pair<ll,ll>>& vec,ll idx,vector<ll>& divs,ll num){
	if(idx==vec.size()){
		divs.push_back(num);
		return;
	}
	for(ll i=0;i<=vec[idx].second;i++){
		divisors(vec,idx+1,divs,num*pow(vec[idx].first,i));
	}
}
void solve(){
	ll n,i,sum=1;
	cin>>n;
	vector<pair<ll,ll>> vec;
	primefacto(n,vec);
	vector<ll> divs;
	divisors(vec,0,divs,1);
	for(auto it=divs.begin();it!=divs.end();it++){
		sum+=*it * etf[*it];
	}
	sum*=n;
	sum/=2;
	cout<<sum<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	sieve();
	ll t;cin>>t;
	while(t--) solve();
	return 0;
}
