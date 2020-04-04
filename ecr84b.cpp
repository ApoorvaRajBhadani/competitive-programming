#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool kingused[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll n,notmar=0,i,k,j,num;
		cin>>n;
		memset(kingused,false,sizeof(kingused));
		for(i=1;i<=n;i++){
			cin>>k;
			bool ismar = false;
			for(j=1;j<=k;j++){
				cin>>num;
				if(!kingused[num] && !ismar){
					kingused[num] = true;
					ismar = true;
				}
			}
			if(!ismar) notmar = i;
		}
		if(notmar){
			for(i=1;i<=n;i++){
				if(!kingused[i]){
					cout<<"IMPROVE\n";
					cout<<notmar<<" "<<i<<endl;
					break;
				}
			}
		}else{
			cout<<"OPTIMAL"<<endl;
		}
	}		
	return 0;
}
