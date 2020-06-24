#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
ll* getLPS(string& p){
	ll len=p.size();
	ll* LPS = new ll[len];
	ll i=1,j=0;
	LPS[0]=0;
	while(i<len){
		if(p[i]==p[j]){
			LPS[i]=j+1;
			i++;
			j++;
		}else{
			if(j!=0){
				j=LPS[j-1];
			}else{
				LPS[i]=0;
				i++;
			}
		}
	}
	return LPS;
}
int main(){
	string pattern;
	cin>>pattern;
	ll* LPS = getLPS(pattern);
	for(auto ch:pattern) cout<<ch<<" ";
	cout<<endl;
	for(ll i=0;i<pattern.size();i++) cout<<LPS[i]<<" ";
	return 0;
}
