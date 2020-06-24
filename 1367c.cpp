#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
//#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll arr[500005];
ll arr2[500005];
void solve(){
	ll i,j,n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	mset(arr2,0);
	fo(i,0,n){
		arr[i]=s[i]-'0';
		if(arr[i]==1){
			j=max(i-k,0ll);
			while(j<=i+k){
				if(arr2[j]>0) j=arr2[j];
				else arr2[j++]=i+k+1;
			}
		}
	}
	//fo(i,0,n) cout<<arr2[i];
	//cout<<endl;
	i=0;
	ll curr=0,ans=0;
	while(i<n){
		if(arr2[i]==0){
			curr++;
			i++;
		}else{
			ans+=curr/(k+1);
			if((curr%(k+1))>0) ans++;
			curr=0;
			i=arr2[i];
		}
	}
	ans+=curr/(k+1);
	if((curr%(k+1))>0) ans++;
	cout<<ans<<endl;
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
