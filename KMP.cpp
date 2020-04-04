#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
int* getLps(string pattern){
	int len=pattern.length();
	int* lps = new int[len];
	int j=0,i=1;
	lps[0]=0;
	while(i<len){
		if(pattern[i]==pattern[j]){
			lps[i]=j+1;
			i++;j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}
bool kmpSearch(string text,string pattern){
	int lentxt = text.length();
	int lenptrn = pattern.length();
	int i=0,j=0;
	int* lps = getLps(pattern);
	while(i<lentxt&& j<lenptrn){
		if(pattern[j]==text[i]){
			i++;j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	if(j==lenptrn) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string text,pattern;
	cin>>text>>pattern;
	int* lps = getLps(pattern);
	fo(i,0,pattern.length()-1) cout<<lps[i]<<" ";
	cout<<endl;
	cout<<kmpSearch(text,pattern);
	return 0;
}













