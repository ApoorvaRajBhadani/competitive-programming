#include<bits/stdc++.h> 
using namespace std;
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
ll remp[1000005],rems[1000005];
ll modexp(ll a,ll b,ll c){
	if(a==0) return 0;
	if(b==0) return 1;
	if(b%2){
		ll smallans = modexp(a,b-1,c);
		ll ans = a%c;
		ans = (ans*smallans)%c;
		return ans;
	}else{
		ll smallans = modexp(a,b/2,c);
		ll ans = (smallans*smallans)%c;
		return ans;
	}
}
void solve(ll caseno){
	ll i,j,a,b,n;
	string s;
	cin>>s>>a>>b;
	n=s.size();
	remp[0]=(s[0]-'0')%a;
	fo(i,1,n){
		remp[i]=(remp[i-1]*10+(s[i]-'0'))%a;
	}
	rems[n-1]=(s[n-1]-'0')%b;
	for(i=n-2;i>=0;i--){
		rems[i]=(rems[i+1]+(s[i]-'0')*modexp(10,n-1-i,b))%b;
	}
	fo(i,0,n-1){
		//cout<<remp[i]<<" "<<rems[i+1]<<endl;
		if(remp[i]==0&&rems[i+1]==0&&s[i+1]!='0'){
			cout<<"YES"<<endl;
			cout<<s.substr(0,i+1)<<endl;
			cout<<s.substr(i+1,n-i-1)<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
