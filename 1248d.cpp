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
bool iscor(string &s){
    ll op=0,i,n=s.size();
    fo(i,0,n){
        if(s[i]=='('){
            op++;
        }
        else{
            if(op>0) op--;
            else return false;
        }
    }
    //cout<<s<<endl;
    if(op==0) return true;
    return false;
}
ll beauty(string s){
    ll i,n=s.size(),ans=0;
    fo(i,0,n){
        string t=s.substr(n-i,i);
        t+=s.substr(0,n-i);
        if(iscor(t)) ans++;
    }
    return ans;
}
void solve(ll caseno){
	ll i,j,n,ans=0,a=1,b=1;
    string s;
    cin>>n>>s;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            swap(s[i],s[j]);
            ll bt = beauty(s);
            swap(s[i],s[j]);
            if(bt>=ans){
                ans=bt;
                a=i+1;
                b=j+1;
            }
        }
    }
    cout<<ans<<endl<<a<<' '<<b<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
        // string s="()()())(()";
        // cout<<iscor(s)<<endl;
		solve(i);
        //cout<<beauty(")))(()")<<endl;
	}
	return 0;
}
