#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
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
ll freq[26];
ll diff[55];
char ans[60];
void solve(){
	ll i,j,ns,nt,cnt=0;
	string s;
	cin>>s;
	ns=s.size();
	mset(freq,0);
	fo(i,0,ns) freq[s[i]-'a']++;
	cin>>nt;
	fo(i,0,nt) cin>>diff[i];
	j=25;
	while(cnt<nt){
		vi pos;
		fo(i,0,nt){
			if(diff[i]==0) pos.pbb(i);
		}
		for(;j>=0;j--){
			if(freq[j]>=pos.size()) break;
		}
		for(auto idx:pos) {
			ans[idx]=(char)(j+'a');
			diff[idx]=-1;
		}
		freq[j]=0;
		fo(i,0,nt){
			if(diff[i]==-1) continue;
			for(auto idx:pos){
				diff[i]-=abs(i-idx);
			}
		}
		cnt+=pos.size();
	}
	fo(i,0,nt) cout<<ans[i];cout<<endl;
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
