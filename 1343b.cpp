#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,j;
	cin>>n;
	if((n/2)%2==1){
		cout<<"NO"<<endl;
		return;
	}
	vector<ll> a,b;
	ll suma=0,sumb=0,even=2,odd=1;
	for(i=0;i<n/2;i++){
		if(i%2==0){
			a.push_back(even);
			b.push_back(odd);
			suma+=even;
			sumb+=odd;
			odd+=2;
			even+=2;
		}else{
			while(true){
				if( (suma+even-sumb)>=odd){
					a.push_back(even);
					odd = (suma+even-sumb);
					b.push_back(odd);
					suma+=even;
					sumb+=odd;
					odd+=2;
					even+=2;
					break;
				}else{
					even+=2;
				}
			}
		}
	}
	cout<<"YES"<<endl;
	for(auto it=a.begin();it!=a.end();it++) cout<<*it<<" ";
	for(auto it=b.begin();it!=b.end();it++) cout<<*it<<" ";
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
