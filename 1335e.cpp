#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
vector<ll> arr;
ll ans;
void compute(vector<ll> nrr){
	//cout<<"here";
	for(auto it=nrr.begin();it!=nrr.end();it++) cout<<*it;
	ll i=0,k;
	ll len = nrr.size();
	if(len==0) return;
	//if(len == 1 ) {
		//ll one = 1;
		//ans = max(ans,one);
		//return;
	//}
	ll j = len-1;
	ll init = nrr[0];
	while(true){
		if(j<=i) break;
		if(arr[i] != arr[j]) break;
		if(arr[i] != init) break;
		i++;j--;
	}
	i--;j++;
	cout<<i<<" "<<j<<" ";
	set<ll> st;
	for(k=i+1;k<j;k++){
		st.insert(arr[k]);
	}
	if(st.size()==1 || st.size()==0){
		cout<<(i+1)*2 +(j-i-1);
		ans = max((i+1)*2 +(j-i-1),ans);
	}
		cout<<endl;
}
void compute2(vector<ll> nrr){
	if(nrr.size()==0) return;
	ll i=-1 , j=nrr.size(),k;
	ll req = nrr[0];
	while( (i+1)<(j-1)){
		if( nrr[i+1] == nrr[j-1] && nrr[i+1]==req){
			i++;j--;
		}else{
			break;
		}
	}
	set<ll> st;
	for(k=i+1;k<=(j-1);k++){
		st.insert(nrr[k]);
	}
	if(st.size()==0 || st.size()==1){
		ll myans = (i+1)*2  + (j-i-1);
		ans = max(ans,myans);
	}
}
void findAns(vector<ll> nrr,ll start,ll n){
	if(start==n) {compute2(nrr); return;}
	ll i;
		findAns(nrr,start+1,n);
		nrr.push_back(arr[start]);
		findAns(nrr,start+1,n);
}
void solve(){
	arr.clear();
	ll n,i;
	cin>>n;
	for(i=0;i<n;i++){
		ll a;
		cin>>a;
		arr.push_back(a);
	}
	vector<ll> nrr;
	ans=0;
	findAns(nrr,0,n);
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
