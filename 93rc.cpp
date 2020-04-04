#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

bool checkpos(ll num,set<int>& st,int k){
	//cout<<st.size()<<" size"<<endl;
	ll pow=0;
	while(num>0){
		if(num%k==0){
			pow++;
			num/=k;
		}else{
			if(st.find(pow) == st.end()){
				st.insert(pow);
				//cout<<"inserted "<<pow<<endl;
				num-=1;
			}else return false;
		}
	}
	//num is now zero
	return true;
}	
int main(){
int t;
cin>>t;
while(t--){
	ll n,k,num,i;
	cin>>n>>k;
	ll arr[n];
	set<int> st;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=0;i<n;i++){
		if(checkpos(arr[i],st,k)){
			continue;
		}else break;
	}
	if(i==n) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
		
return 0;
}
