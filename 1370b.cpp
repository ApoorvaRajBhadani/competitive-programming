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
	ll i,j,n,cnt=0;
    cin>>n;
    vi odds,evens;
    fo(i,0,2*n){
        cin>>arr[i];
        if(arr[i]%2==0) evens.pbb(i+1);
        else odds.pbb(i+1);
    }
    i=j=0;
    //i for even j for odd
    ll no=odds.size();
    ll ne=evens.size();
    while(i+1<ne && cnt<n-1){
        cout<<evens[i]<<" "<<evens[i+1]<<endl;
        i+=2;
        cnt++;
    }
    while(j+1<no && cnt<n-1){
        cout<<odds[j]<<" "<<odds[j+1]<<endl;
        j+=2;
        cnt++;
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
