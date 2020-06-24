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
ll arr[505];
void solve(){
	ll i,j,n,pr=0,nz=0,no=0;
	cin>>n;
	bool sorted=true;
	fo(i,0,n){
		cin>>arr[i];
		if(arr[i]<pr) sorted=false;
		pr = arr[i];
	}
	fo(i,0,n){
		cin>>j;
		if(j==0) nz++;
		else no++;
	}
	if(sorted){
		cout<<"Yes"<<endl;
	}else{
		if(no!=0 && nz!=0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
