#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool edges[26][26];
void dfs(bool* visited,bool* charcame,int start){
	visited[start]=true;
	for(int i=0;i<26;i++){
		if(i==start) continue;
		if(!visited[i]&&edges[start][i]&&charcame[i]){
			dfs(visited,charcame,i);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,i,j,ans=0;
	string s;
	cin>>n;
	memset(edges,0,sizeof(edges));
	bool* charcame= new bool[26];
	fo(i,0,25) charcame[i]=0;
	for(i=0;i<n;i++){
		cin>>s;
		int prev=s[0]-'a',curr;
		charcame[prev]=1;
		for(j=1;j<s.size();j++){
			curr=s[j]-'a';
			charcame[curr]=1;
			edges[prev][curr]=edges[curr][prev]=1;
		}
	}
	bool* visited=new bool[26];
	fo(i,0,25) visited[i]=0;
	for(i=0;i<26;i++){
		if(!visited[i]&&charcame[i]){
			ans++;
			dfs(visited,charcame,i);
		}
	}
	cout<<ans;
	return 0;
}
