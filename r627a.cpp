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
		int n,i,a0,a;
		cin>>n;
		cin>>a0;
		bool ans = true;
		for(i=1;i<n;i++){
			cin>>a;
			//cout<<a<<endl;
			int cc = abs(a0-a);
			if(cc%2!=0){
				ans = false;
			}
		}
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
