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
bool answer(vi& vec,vi& ans,ll n){
    ll i;
    fo(i,0,n-1){
        if(vec[i]==1){
            if(vec[i+1]==0){
                ans.pbb(i+1);
                vec[i]=0;
                vec[i+1]=1;
            }else if(vec[i+1]==1){
                ans.pbb(i+1);
                vec[i]=0;
                vec[i+1]=0;
                i++;
            }
        }
    }
    if(vec[n-1]==1) return false;
    return true;
}
void solve(ll caseno){
	ll i,j,n;
    cin>>n;
    string s;
    cin>>s;
    vi vecw1,vecb1,ans;
    fo(i,0,n){
        if(s[i]=='B'){
            vecb1.pbb(1);
            vecw1.pbb(0);
        }else{
            vecb1.pbb(0);
            vecw1.pbb(1);
        }
    }
    bool ispos=answer(vecw1,ans,n);
    if(ispos){
        cout<<ans.size()<<endl;
        for(auto idx:ans) cout<<idx<<' ';
        cout<<endl;
        return;
    }
    ans.clear();
    ispos = answer(vecb1,ans,n);
    if(ispos){
        cout<<ans.size()<<endl;
        for(auto idx:ans) cout<<idx<<' ';
        cout<<endl;
        return;
    }
    cout<<-1<<endl;
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
