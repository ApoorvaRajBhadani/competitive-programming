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
ll arr[45];
void solve(){
	ll i,j,n,wrong1=0,wrong0=0;
	cin>>n;
	fo(i,0,n){
		cin>>arr[i];
		ll p1=arr[i]%2;
		ll p2=i%2;
		if(p1!=p2){
			if(p1==0) wrong0++;
			else if(p1==1) wrong1++;
		}
	}
	if(wrong1!=wrong0){
		cout<<-1<<endl;
	}else{
		cout<<wrong1<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
