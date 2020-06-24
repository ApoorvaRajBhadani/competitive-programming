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
#define PL1 "Ashishgup"
#define PL2 "FastestFinger"
void solve(ll caseno){
	ll i,j,n,x=0,y=0;
    cin>>n;
    if(n==1){
        cout<<PL2<<endl;
        return;
    }
    while(n%2==0) {
        n/=2;
        x++;
    }
    for(i=3;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            y++;
        }
    }if(n>1) y++;

    if(x==0){
        cout<<PL1<<endl;
    }else if(x==1){
        if(y==0){
            cout<<PL1<<endl;
        }else if(y==1){
            cout<<PL2<<endl;
        }else{
            cout<<PL1<<endl;
        }
    }else {
        if(y==0){
            cout<<PL2<<endl;
        }else{
            cout<<PL1<<endl;
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
