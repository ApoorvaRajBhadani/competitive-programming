#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int i,mxl=0,c=0,len = s.size();
		for(i=0;i<len;i++){
			if(s[i]=='R') {
				mxl = max(c,mxl);
				c=0;
			}
			else c++;
		}
		mxl=max(c,mxl);
		cout<<mxl+1<<"\n";
	}
	return 0;
}
