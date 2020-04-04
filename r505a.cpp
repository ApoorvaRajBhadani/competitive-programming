#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	int n,i;
	cin>>n;
	string s;
	cin>>s;
	map<char,int> mp;
	for(i=0;i<s.size();i++){
		mp[s[i]]++;
	}
	if(mp.size()==1){
		cout<<"Yes";
	}else{
		for(auto it=mp.begin();it!=mp.end();it++){
			if(it->second >=2 ) {
				cout<<"Yes";
				return 0;
			}
		}
		cout<<"No";
	}
return 0;
}
