#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
int t,n,m,i,ans,temp;
cin>>t;
while(t--){
	ans = INT_MAX;
	map<int,int> fruits;
	cin>>n>>m;
	int basket[n],price[n];
	for(i=0;i<n;i++){
		cin>>basket[i];
	}
	for(i=0;i<n;i++){
		cin>>price[i];
	}
	for(i=0;i<n;i++){
		fruits[basket[i]] += price[i];
	}
	for(auto it=fruits.begin();it!=fruits.end();it++){
		ans = min(it->second,ans);
	}
	cout<<ans<<endl;
}
return 0;
}
