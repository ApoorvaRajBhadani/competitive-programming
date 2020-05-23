#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,i,mask,ans=1,j,reqnum;
	cin>>n;
	ll dp[n+1];
	for(i=1;i<=n;i++) dp[i]=i;
	for(mask=1;mask<=n;mask++){
		ans*=dp[mask];
		j=0;
		while(true){
			//cout<<mask<<" "<<j<<endl;
			if((mask&(1<<j)) == 0){
				reqnum = mask|(1<<j);
				//cout<<reqnum<<endl;
				if(reqnum>n) break;
				dp[reqnum]--;
			}
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
