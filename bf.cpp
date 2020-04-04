#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
#define tezz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
ll printNcR(ll n, ll r) 
{ 
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m = __gcd(p, k); 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p;
} 
ll ansfun2(vector<ll> vt,ll player){
	ll i,j,k,len = vt.size();
	if(len == 0){
		if(player == 1) return 1;
		else return 0;
	}
	ll count = 1;
	for(i=0;i<len;i++){
		ll qt = vt[i];
		for(j=1;j<qt;j++){
			vector<ll> nvt;
			for(k=0;k<len;k++){
				if(k==i) nvt.push_back(vt[k] - j);
				else nvt.push_back(vt[k]);
			}
			count *= ansfun2(nvt,player^1);
		}
		//j is qt
		vector<ll> nvt;
		for(k=0;k<len;k++){
			if(k!=i) nvt.push_back(vt[k]);
		}
		count *= ansfun2(nvt,player^1);
	}
	return count;
}
ll ansfun(vector<ll> vt,ll player){
	ll i,j,k,len = vt.size();
	if(len == 0){
		if(player == 1) return 1;
		else return 0;
	}
	ll count = 0;
	for(i=0;i<len;i++){
		ll qt = vt[i];
		for(j=1;j<qt;j++){
			vector<ll> nvt;
			for(k=0;k<len;k++){
				if(k==i) nvt.push_back(vt[k] - j);
				else nvt.push_back(vt[k]);
			}
			count += printNcR(qt,j)*ansfun2(nvt,player^1);
		}
		//j is qt
		vector<ll> nvt;
		for(k=0;k<len;k++){
			if(k!=i) nvt.push_back(vt[k]);
		}
		count += ansfun2(nvt,player^1);
	}
	return count;
}
int main(){
	tezz
	ll t;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n;
		ll arr[n];
		fo(i,0,n-1)cin>>arr[i];
		cin>>q;
		while(q--){
			ll l,r;
			cin>>l>>r;
			map<ll,ll> mp;
			fo(i,l-1,r-1) mp[arr[i]]++;
			vector<ll> vt;
			for(auto it=mp.begin();it!=mp.end();it++){
				vt.push_back(it->second);
			}
			cout<< ansfun(vt,0)<<endl;
		}
	}
	return 0;
}
