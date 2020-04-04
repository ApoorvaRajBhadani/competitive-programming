#include<bits/stdc++.h> 
#include<climits> 
using namespace std;
typedef long long int ll;
int cut[3],n;
int helper(int n,int* dp){
	int op1,op2,op3;
	if(n<0) return INT_MIN;
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	op1 = 1+helper(n-cut[0],dp);
	op2 = 1+helper(n-cut[1],dp);
	op3 = 1+helper(n-cut[2],dp);
	//cout<<"at "<<n<<" "<<max(op1,max(op2,op3));
	return dp[n]=max(op1,max(op2,op3));
}
int main(){
	cin>>n>>cut[0]>>cut[1]>>cut[2];
	sort(cut,cut+3);
	int *dp = new int[n+1];
	for(int i=0;i<=n;i++) dp[i]=-1;
	int ans = helper(n,dp);
	cout<<ans;
	return 0;
}
