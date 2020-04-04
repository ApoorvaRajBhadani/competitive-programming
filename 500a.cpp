#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,t,i;
	cin>>n>>t;
	t--;
	int arr[n-1],curr=0;
	fo(i,0,n-2) cin>>arr[i];
	bool ans = false;
	while(curr!=n-1){
		if(curr==t){
			ans = true;
			break;
		}
		curr+=arr[curr];
	}
	if(curr==t){
			ans = true;
		}
	cout<<(ans?"YES":"NO");
	return 0;
}
