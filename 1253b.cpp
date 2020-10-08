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
ll events[100005];
ll status[1000005];
void solve(ll caseno){
	ll i,j,n;
    cin>>n;
    fo(i,0,n) cin>>events[i];
    vi ans;
    mset(status,0);
    ll de=0,pres=0;
    map<ll,bool> mp;
    fo(i,0,n){
        ll empl=abs(events[i]);
        ll eve = events[i]/empl;
        if(eve==1){
            if(status[empl]==0 && mp[empl]==false){
                de++;
                status[empl]++;
                mp[empl]=true;
                pres++;
            }else{
                cout<<-1<<endl;
                return;
            }
        }else{
            if(status[empl]==1){
                de++;
                status[empl]=0;
                pres--;
            }else{
                cout<<-1<<endl;
                return;
            }
        }
        if(pres==0 && de>0){
            ans.pbb(de);
            de=0;
            mp.clear();
        }
    }
    if(pres>0){
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for(auto dye:ans) cout<<dye<<' ';cout<<endl;
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
