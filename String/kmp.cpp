#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
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
			LPS[i++]=(j++)+1;
		}else{
			if(j!=0) j=LPS[j-1];
			else LPS[i++]=0;
		}
	}
	return LPS;
}
bool kmpsearch(string& s,string& p){
	ll lens=s.size(),lenp=p.size();
	ll i=0,j=0;
	ll* LPS = getLPS(p);
	while(i<lens&&j<lenp){
		if(s[i]==p[j]){
			i++;j++;
		}else{
			if(j!=0) j=LPS[j-1];
			else i++;
		}
		//following code will print all occurence of pattern
		//if(j==lenp){
			//cout<<i-1<<endl;
			//j=LPS[j-1];
		//}
	}
	if(j==lenp) return true;
	return false;
}
int main(){
	string text,pattern;
	cin>>text>>pattern;
	ll* LPS = getLPS(pattern);
	if(kmpsearch(text,pattern)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
