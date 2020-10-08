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
ll check(string s,ll i,ll j){
    ll it,c=0;
    for(it=0;it<s.size();it++){
        if(c%2==0){
            if(s[it]==(char)('0'+i)){
                c++;
            }
        }else{
            if(s[it]==(char)('0'+j)){
                c++;
            }
        }
    }
    if(c%2==1 && i!=j) c--;
    //cout<<i<<' '<<j<<' '<<s.size()-c<<endl;
    return s.size()-c;
}
void solve(ll caseno){
	ll i,j,ans=INT_MAX;
    string s;
    cin>>s;
    for(i=0;i<=9;i++){
        for(j=0;j<=9;j++){
            ans = min(ans,check(s,i,j));
        }
    }
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
