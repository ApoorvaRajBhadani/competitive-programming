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
vi arr11,arr01,arr10;
void solve(ll caseno){
	ll i,j,n,k,t,a,b,n1,n2,ans=INT_MAX;
    cin>>n>>k;
    fo(i,0,n){
        cin>>t>>a>>b;
        if(a==1&&b==1) arr11.pbb(t);
        else if(a==1&&b==0) arr10.pbb(t);
        else if(a==0&&b==1) arr01.pbb(t);
    }
    n1=arr11.size();
    n2=min(arr01.size(),arr10.size());
    if(n1+n2<k){
        cout<<-1<<endl;
        return;
    }
    sort(all(arr11));
    sort(all(arr01));
    sort(all(arr10));
    fo(i,1,arr11.size()){
        arr11[i]+=arr11[i-1];
    }
    fo(i,1,n2){
        arr01[i]+=arr01[i-1];
        arr10[i]+=arr10[i-1];
    }
    for(i=0;i<=n1;i++){
        ll mytime=0;
        if(i>0){
            mytime+=arr11[i-1];
        }
        j=k-i;
        if(j<=n2){
            if(j>0) mytime+=arr10[j-1]+arr01[j-1];
            ans = min(ans,mytime);
        }
    }
    cout<<ans<<endl;
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
