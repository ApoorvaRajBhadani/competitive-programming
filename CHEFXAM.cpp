#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll dp[51][1001];
ll ispresent[51][1001];
ll findAns(ll* rangestart,ll* rangeend,ll day,ll topleft,ll k){
	if(day == k){
		if(topleft==0) return 1;
		else return 0;
	}
	if(ispresent[day][topleft]){
		return dp[day][topleft];
	}
	ll i,start = rangestart[day],end= rangeend[day];
	ll ans=0;
	for(i=start;i<=end;i++){
		if(topleft-i>=0){
			ans=(ans + findAns(rangestart,rangeend,day+1,topleft-i,k))%MOD;
		}
	}
	ispresent[day][topleft]=true;
	return dp[day][topleft]=ans;
}
void solve(){
	ll k,n,i;
	cin>>k>>n;
	ll* rangestart = new ll[k];
	ll* rangeend = new ll[k];
	for(i=0;i<k;i++)cin>>rangestart[i]>>rangeend[i];
	memset(dp,0,sizeof(dp));
	memset(ispresent,false,sizeof(ispresent));
	ll ans = findAns(rangestart,rangeend,0,n,k);
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
