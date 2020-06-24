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
bool island[5][100005];
void solve(ll caseno){
	ll i,j,n,q,r,c,blocks=0;
    cin>>n>>q;
    for(i=1;i<=n;i++) island[1][i]=island[2][i]=true;
    while(q--){
        cin>>r>>c;
        ll ib=0,fb=0;
        if(r==1){
            if(c-1>=1) if(!island[2][c-1]&&!island[r][c])ib++;
            if(          !island[2][c]&&!island[r][c])  ib++;
            if(c+1<=n)if(!island[2][c+1]&&!island[r][c])ib++; 
        }else{
            if(c-1>=1)if(!island[1][c-1]&&!island[r][c])ib++;
            if(          !island[1][c]&&!island[r][c])  ib++;
            if(c+1<=n)if(!island[1][c+1]&&!island[r][c])ib++;
        }
        island[r][c]=!island[r][c];
        if(r==1){
            if(c-1>=1)if(!island[2][c-1]&&!island[r][c])fb++;
            if(          !island[2][c]&&!island[r][c])  fb++;
            if(c+1<=n)if(!island[2][c+1]&&!island[r][c])fb++; 
        }else{
            if(c-1>=1)if(!island[1][c-1]&&!island[r][c])fb++;
            if(          !island[1][c]&&!island[r][c])  fb++;
            if(c+1<=n)if(!island[1][c+1]&&!island[r][c])fb++;
        }
        blocks+=(fb-ib);
        if(blocks<=0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
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
