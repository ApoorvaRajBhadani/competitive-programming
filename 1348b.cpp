#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,k,i,j;
	cin>>n>>k;
	bool pos = true;
	ll arr[n];
	ll mx=LLONG_MIN;
	set<ll> st;
	for(i=0;i<n;i++) {
		cin>>arr[i];
		mx=max(mx,arr[i]);
		st.insert(arr[i]);
	}
	if(st.size()>k) pos= false;
	if(!pos){
		cout<<-1<<endl;
		return;
	}
	cout<<n*k<<endl;
	for(i=0;i<n;i++){
		for(auto it=st.begin();it!=st.end();it++){
			cout<<*it<<" ";
		}
		for(j=1;j<=(k-st.size());j++){
			cout<<n<<" ";
		}
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}
