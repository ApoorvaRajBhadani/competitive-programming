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
ll arr[100005];
void solve(ll caseno){
	ll i,j,n,vis=-1;
    cin>>n;
    fo(i,0,n) cin>>arr[i];
    bitset<32> barr[n];
    fo(i,0,n) barr[i]=arr[i];
    for(j=31;j>=0;j--){
        ll lastat=-1;
        fo(i,0,n){
            if(barr[i].test(j)){
                if(lastat==-1) lastat=i;
                else {
                    lastat=-2;
                    break;
                }
            }
        }
        if(lastat>=0){
            vis=lastat;
            break;
        }
    }
    if(vis>=0)cout<<arr[vis]<<" ";
    fo(i,0,n){
        if(i==vis) continue;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
