#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int isEvenOnes(int num){
	bool iseven = true;
	while(num>0){
		if(num&1) iseven= !iseven;
		num = num>>1;
	}
	if(iseven) {return 1;}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int i,n,q,noeon=0,num;
		cin>>n>>q;
		for(i=0;i<n;i++){
			cin>>num;
			noeon += isEvenOnes(num);
		}
		//solving querries
		while(q--){
			cin>>num;
			bool ispeven = isEvenOnes(num);
			if(ispeven){
				cout<<noeon<<" "<<n-noeon<<"\n";
			}else{
				cout<<n-noeon<<" "<<noeon<<"\n";
			}
		}
	}
	return 0;
}
