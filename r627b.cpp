#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,i,num,ind[5001],f[5001];
		for(i=1;i<=5000;i++){
			f[i]=0;
			ind[i]=INT_MAX;
		}
		cin>>n;
		bool ans = false;
		for(i=0;i<n;i++){
			cin>>num;
			f[num]++;
			if(f[num]>=2 && ind[num]<i-1) ans = true;
			ind[num] = i;
			if(f[num]>=3) ans = true;
		}
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
