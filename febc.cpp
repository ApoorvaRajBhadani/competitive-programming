#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ll t;
	cin>>t;
	ll n,m,i,j;
	while(t--){
		cin>>n>>m;
		string s;
		ll arr[m],f[26]={0},k=m;
		cin>>s;
		for(i=0;i<m;i++){
			cin>>arr[i];
			arr[i]-=1;
		}
		sort(arr,arr+m);
		for(i=0,j=0;i<s.size();i++){
			f[s[i]-'a']+=(1+k);
			if(i==arr[j]){
				while(arr[j]==i){
					j++;
					k--;
				}
			}
		}
		for(i=0;i<26;i++) {
			cout<<f[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
