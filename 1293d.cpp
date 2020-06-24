#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
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
ll xi,yi,ax,ay,bx,by,xs,ys,t;
vector<pii> vec;
ll answer(ll i,ll j,ll k){
    //cout<<i<<" "<<j<<" "<<k<<endl;
    ll x1,y1,x2,y2,x3,y3,myt=0;
    x1=vec[i].ff;
    x2=vec[j].ff;
    x3=vec[k].ff;
    y1=vec[i].ss;
    y2=vec[j].ss;
    y3=vec[k].ss;
    myt+=abs(xs-x2)+abs(ys-y2);
    myt+=abs(x3-x1)+abs(y3-y1);
    myt+=min(abs(x3-x2)+abs(y3-y2),abs(x1-x2)+abs(y1-y2));
    if(myt<=t){
        return k-i+1;
    }
    return 0;
}
void solve(ll caseno){
	ll i,j,k,x,y,reacht,n,ans=0,prevt=LLONG_MAX;
    cin>>xi>>yi>>ax>>ay>>bx>>by>>xs>>ys>>t;
    x=xi;
    y=yi;
    for(i=1;true;i++){
        reacht=abs(xs-x)+abs(ys-y);
        //cout<<reacht<<endl;
        if(reacht<=t){
            vec.pbb(mpp(x,y));
        }else{
            if(reacht>prevt){
                break;
            }
        }
        ll nx=x*ax+bx;
        ll ny=y*ay+by;
        x=nx;
        y=ny;
        prevt=reacht;
    }
    n=vec.size();
    //cout<<n<<endl;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            for(k=j;k<n;k++){
                ans=max(ans,answer(i,j,k));
            }
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
