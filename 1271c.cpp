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
ll n,homex[200005],homey[200005];
ll answerup(ll y){
    if(y<0||y>1e9) return -1;
    ll i,ans=0;
    fo(i,0,n){
        if(homey[i]>=y) ans++;
    }
    return ans;
}
ll answerdown(ll y){
    if(y<0||y>1e9) return -1;
    ll i,ans=0;
    fo(i,0,n){
        if(homey[i]<=y) ans++;
    }
    return ans;
}
ll answerleft(ll x){
    if(x<0||x>1e9) return -1;
    ll i,ans=0;
    fo(i,0,n){
        if(homex[i]<=x) ans++;
    }
    return ans;
}
ll answerright(ll x){
    if(x<0||x>1e9) return -1;
    ll i,ans=0;
    fo(i,0,n){
        if(homex[i]>=x) ans++;
    }
    return ans;
}
void solve(ll caseno){
	ll i,j,sx,sy,ans=0,myans,px,py;
    cin>>n>>sx>>sy;
    fo(i,0,n){
        cin>>homex[i]>>homey[i];
    }
    myans=answerleft(sx-1);
    if(myans>=ans){
        ans=myans;
        px=sx-1;
        py=sy;
    }
    myans=answerup(sy+1);
    if(myans>=ans){
        ans=myans;
        px=sx;
        py=sy+1;
    }
    myans=answerright(sx+1);
    if(myans>=ans){
        ans=myans;
        px=sx+1;
        py=sy;
    }
    myans=answerdown(sy-1);
    if(myans>=ans){
        ans=myans;
        px=sx;
        py=sy-1;
    }
    cout<<ans<<endl;
    cout<<px<<' '<<py<<endl;
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
