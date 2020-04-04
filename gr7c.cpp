#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 998244353
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool compare(pair<ll,ll> a,pair<ll,ll> b){
	return a.first>b.first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,k,i;
	cin>>n>>k;
	vector<pair<ll,ll>> arr;
	for(i=0;i<n;i++){
		ll num;
		cin>>num;
		arr.push_back(make_pair(num,i));
	}
	sort(arr.begin(),arr.end(),compare);
	ll arrn[k],ans1=0;
	for(i=0;i<k;i++){
		arrn[i] = arr[i].second;
		ans1+=arr[i].first;
	}
	sort(arrn,arrn+k);
	ll ans2 = 1;
	for(i=1;i<k;i++){
		//cout<<arrn[i]<<' '<<arrn[i-1]<<endl;
		ans2 =  ((ans2%MOD) *   ((arrn[i]-arrn[i-1])%MOD))%MOD;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
