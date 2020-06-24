#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
bool pres[1050];
void solve(){
	ll i,j,n,netxor=0;
	cin>>n;
	vector<ll> arr(n);
	mset(pres,false);
	fo(i,0,n){
		cin>>arr[i];
		pres[arr[i]]=true;
		netxor^=arr[i];
	}
	if(n%2==1){
		cout<<-1<<endl;
		return;
	}
	if((n/2)%2==0){
		if(netxor==0){
			for(i=1;i<=1024;i++){
				if(pres[arr[0]^i]&&(!pres[i]||(pres[0]&&pres[i]))){
					cout<<i<<endl;
					return;
				}
			}
		}else{
			cout<<-1<<endl;
		}
	}else{
		if(pres[arr[0]^netxor]){
			cout<<netxor<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}
