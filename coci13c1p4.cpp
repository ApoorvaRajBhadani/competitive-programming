#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
struct jwel{
	ll m,v;
};
bool compare(jwel a,jwel b){
	if(a.v!=b.v)
	return a.v>b.v;
	return a.m<b.m;
}
int main(){
	ll n,k,i,value=0;
	cin>>n>>k;
	vector<jwel> arr;
	ll bags[k];
	for(i=0;i<n;i++){
		ll m,v;
		cin>>m>>v;
		jwel temp;
		temp.m=m;
		temp.v=v;
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end(),compare);
	for(i=0;i<k;i++) cin>>bags[i];
	sort(bags,bags+k);
	for(i=0;i<k;i++){
		for(auto j=arr.begin();j!=arr.end();j++){
			if((*j).m<=bags[i]){
				//can be taken
				value+=(*j).v;
				arr.erase(j);
				break;
			}
		}
	}
	cout<<value;		
	return 0;
}
