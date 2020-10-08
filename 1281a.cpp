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
string sarr[4]={"op","used","usam","adinm"};
void solve(ll caseno){
	ll i,j,n;
    string s,suff="";
    cin>>s;
    n=s.size();
    for(i=n-1;i>=0;i--){
        suff+=s[i];
        if(suff.size()==2){
            if(suff==sarr[0]){
                cout<<"FILIPINO"<<endl;
                return;
            }
        }else if(suff.size()==4){
            if(suff==sarr[1]||suff==sarr[2]){
                cout<<"JAPANESE"<<endl;
                return;
            }
        }if(suff.size()==5){
            if(suff==sarr[3]){
                cout<<"KOREAN"<<endl;
                return;
            }
        }
    }
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
