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
ll arr[100005];
bool used[100005];
ll cnt[100005];
void solve(){
	ll i,j,n;
	cin>>n;
	mset(cnt,0);
	mset(used,false);
	fo(i,0,n){
		cin>>arr[i];
		cnt[arr[i]]++;
	}
	vector<ll> ans;
	ll p1=0,p2=0;//p1-smallest unused,p2-max unused&usable;
	fo(i,0,n){
		if(cnt[p1]==0){
			cout<<p1<<" ";
			used[p1]=true;
			while(used[p1]) p1++;
		}else{
			while(used[p2]||cnt[p2]>0) p2++;
			cout<<p2<<" ";
			used[p2]=true;
		}
		cnt[arr[i]]--;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
