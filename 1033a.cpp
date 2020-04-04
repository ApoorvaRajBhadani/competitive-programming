#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
#define tezz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
	tezz
	int n;
	cin>>n;
	int arr[n];
	fo(i,0,n-1) cin>>arr[i];
	fo(i,1,n){
		map<int,int> mp;
		mp[i]++;
		fo(j,0,n-1){
			mp[arr[j]]++;
			if(mp[arr[j]]==2) {
				cout<<arr[j]<<" ";
				break;
			}
		}
	}
	return 0;
}
