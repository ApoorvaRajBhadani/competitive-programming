//p	j1	j2	j3	j4
//1	7	2	9	10
//2	1	8	7	6
//3	10	11	12	3
//4	12	11	4	6
//find min work load such that one person one job and vice versa
#include<bits/stdc++.h> 
using namespace std;
int minCost(int cost[4][4],int n,int p,int mask,int* dp){
	if(p==n) return 0;
	if(dp[mask]!=INT_MAX) return dp[mask];
	int minimum = INT_MAX;
	int i,j;
	for(i=0;i<4;i++){
		if(!(mask & (1<<i))){
			int ans = minCost(cost,n,p+1,mask | (1<<i),dp) + cost[p][i];
			if(ans<minimum) minimum = ans;
		}
	}
	return dp[mask]=minimum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int cost[4][4];
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cin>>cost[i][j];
		}
	}
	int* dp = new int[1<<4];
	//recursive
	for(i=0;i<(1<<4);i++) dp[i]=INT_MAX;
	cout<<minCost(cost,4,0,0,dp)<<endl;
	//iterative
	for(i=0;i<(1<<4);i++) dp[i]=INT_MAX;
	dp[0]=0;
	for(i=0;i<(1<<4)-1;i++){
		int k=0,mc=i;
		while(mc>0){
			if(mc&1 == 1) k++;
			mc = mc>>1;
		}
		for(j=0;j<4;j++){
			if(!(i&(1<<j))){
				dp[i|(1<<j)] = min(dp[i|(1<<j)],dp[i]+cost[k][j]);
			}
		}
	}
	cout<<dp[(1<<4) -1];
	return 0;
}
