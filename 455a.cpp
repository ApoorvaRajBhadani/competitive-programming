	#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ll c[100001]={0},dp[100001]={0},i,n;
	cin>>n;
    for(i=0;i<n;i++){
		int t;
		cin>>t;
		c[t]++;
	}
    dp[1]=c[1];
    for(i=2;i<=100000;i++){
        dp[i]=max(dp[i-1],c[i]*i+dp[i-2]);
    }
    cout<< dp[100000];
    return 0;
}
