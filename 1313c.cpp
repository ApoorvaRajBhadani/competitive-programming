#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,i,j;
	cin>>n;
	ll arr[n];
	bool came[101];
	for(i=1;i<=100;i++) came[i]=false;
	vector<ll> idxfilled;
	for(i=0;i<n;i++){
		cin>>arr[i];
		came[arr[i]]=true;
		if(arr[i]>0){
			idxfilled.push_back(i);
		}
	}
	if(idxfilled.size()==0){
		arr[0]=1;
		idxfilled.push_back(0);
		came[1]=true;
	}
	stack<ll> odd,even;
	for(i=1;i<=n;i++){
		if(!came[i]){
			if(i%2==0) even.push(i);
			else odd.push(i);
		}
	}
	for(j=idxfilled[0]-1;j>=0;j--){
		if(arr[idxfilled[0]]%2==0){
			if(even.size()>0) {arr[j]=even.top();even.pop();}
			else {arr[j]=odd.top();odd.pop();}
		}else{
			if(odd.size()>0) {arr[j]=odd.top();odd.pop();}
			else {arr[j]=even.top();even.pop();}
		}
	}
	for(i=0;i<idxfilled.size();i++){
		ll idx=idxfilled[i];
		ll filled = arr[idx];
		if(filled%2==0){
			for(j=idx+1;arr[j]==0&&j<n;j++){
				if(even.size()>0) {arr[j]=even.top();even.pop();}
				else {arr[j]=odd.top();odd.pop();}
			}
		}else{
			for(j=idx+1;j<n;j++){
				if(arr[j]>0) break;
				if(odd.size()>0) {arr[j]=odd.top();odd.pop();}
				else {arr[j]=even.top();even.pop();}
			}
		}
	}
	ll cnt=0;
	for(i=0;i<(n-1);i++) {
		cout<<arr[i]<<" ";
		if((arr[i]%2)!=(arr[i+1]%2)) cnt++;
	}
	cout<<endl;
	cout<<cnt<<endl;
	return 0;
}











