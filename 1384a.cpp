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
ll arr[110];
void solve(ll caseno){
	ll i,j,n;
    cin>>n;
    string sample="";
    fo(i,0,200) sample+='a';
    vector<string> vec(n+1,sample);
    fo(i,1,n+1){
        cin>>arr[i];
    }
    fo(i,1,n+1){
        fo(j,0,arr[i]){
            vec[i][j] = vec[i-1][j];
        }
        for(;j<200;j++){
            char ch = vec[i-1][j];
            if(ch=='z') ch='a';
            else ch++;
            vec[i][j] = ch;
        }
    }
    for(i=0;i<=n;i++){
        cout<<vec[i]<<endl;
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
