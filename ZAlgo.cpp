#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void buildZ(int* Z,string str){
	int l,r,i,n;
	l=r=0;n=str.length();
	for(i=1;i<n;i++){
		if(i>r){
			l=i;
			r=i;
			while(str[r]==str[r-l] && r<n){
				r++;
			}
			Z[i]=r-l;
			r--;
		}else{
			int k = i-l;
			if(Z[k]+i<=r){
				Z[i]=Z[k];
			}else{
				l=i;
				while(r<n && str[r]==str[r-l]){
					r++;
				}
				Z[i]=r-l;
				r--;
			}
		}
	}
}
void searchString(string text,string pattern){
	string str = pattern+"$"+text;
	int n=str.length();
	int* Z = new int[n]();
	buildZ(Z,str);
	for(int i=0;i<n;i++){
		if(Z[i]==pattern.length()){
			cout<<i-pattern.length()-1<<endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string text,pattern;
	cin>>text>>pattern;
	searchString(text,pattern);
	return 0;
}
