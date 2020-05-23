#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
//memoisation
ll lcsh(char* s,char* t,ll m,ll n,ll** dp,bool** visit,string &answer){
	//already calculated
	//cout<<answer<<endl;
	if(visit[m][n]) return dp[m][n];
	//base case
	if(m==0 || n==0) {
		return 0;
	}
	//relation
	ll ans =0;
	if(s[0]==t[0]) {
		answer+=s[0];
		ans = 1+lcsh(s+1,t+1,m-1,n-1,dp,visit,answer);
		//cout<<s[0]<<endl
	}
	else{
		string myans1 = answer;
		ll op1 = lcsh(s+1,t,m-1,n,dp,visit,myans1);
		string myans2 = answer;
		ll op2 = lcsh(s,t+1,m,n-1,dp,visit,myans2);
		if(op1>op2) {
			ans = op1;
			answer = myans1;
		}
		else {
			ans = op2;
			answer = myans2;
		}
	}
	visit[m][n]=true;
	return dp[m][n]=ans;
}
ll lcs_length(char* s,char* t){
	ll i,j,m = strlen(s),n = strlen(t);
	ll** dp = new ll*[m+1];
	for(i=0;i<=m;i++){
		dp[i] = new ll[n+1];
	}
	bool **visit = new bool*[m+1];
	for(i=0;i<=m;i++) {
		visit[i] = new bool[n+1];
		for(j=0;j<=n;j++) visit[i][j]=false;
	}
	string aaa="";
	ll ans=lcsh(s,t,m,n,dp,visit,aaa);
	for(i=0;i<=m;i++){
		delete [] dp[i];
		delete [] visit[i];
	}
	delete [] dp;
	delete [] visit;
	return ans;
}
//tabulation with lcs string
string lcs_i(char* s,char* t){
	ll m = strlen(s);
	ll n = strlen(t);
	ll dp[m+1][n+1];
	ll i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0||j==0) dp[i][j]=0;
			else if(s[i-1]==t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	//cout<<dp[m][n]<<endl;
	ll index = dp[m][n];
	i=m;j=n;
	char lcsstr[index+1];
	lcsstr[index]='\0';
	index--;
	while(i>0&&j>0){
		if(s[i-1]==t[j-1]){
			lcsstr[index] = s[i-1];
			//cout<<s[i-1]<<endl;
			i--;j--;index--;
		}else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		}else j--;
	}
	return lcsstr;
}
void solve(){
	ll i,j;
	char s[3005],t[3005];
	cin>>s>>t;
	//cout<<lcs_length(s,t)<<endl;
	cout<<lcs_i(s,t)<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
