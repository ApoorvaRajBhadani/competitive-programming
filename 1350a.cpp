#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
ll spf[1000001];
void pc(){
	ll i,j;
	for(i=0;i<=1000000;i++) spf[i]=i;
	for(i=2;i<=1000000;i++){
		if(spf[i]==i){
			for(j=i+i;j<=1000000;j+=i){
				if(spf[j]==j) spf[j]=i;
			}
		}
	}
	//for(i=0;i<=100;i++) cout<<spf[i]<<endl;
}
void solve(){
	ll n,k;
	cin>>n>>k;
	if(n%2==0){
		n+=(k*2);
	}
	else {
		n+=spf[n];
		//cout<<n<<endl;
		n+=(k-1)*2;
	}
	cout<<n<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	pc();
	ll t;
	cin>>t;
	while(t--)solve();
	return 0;
}
