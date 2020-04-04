#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
bool helper(ll s,ll m,char* ans){
	int i;
	if(s>9*m) return false;
	if(m==1){
		if(s<=9){
			ans[m-1]=(char)(s+48);
			return true;
		}else if(s>=10){
			return false;
		}
	}
	for(i=0;i<=9;i++){
		ans[m-1] = (char)(i+48);
		bool cond=helper(s-i,m-1,ans);
		if(cond) break;
	}
	return true;
}
/*
bool helper2(int s,int m,char* ans2,bool pos){
	cout<<s<<" "<<m<<endl;
	int i;
	if(m>=1&&s<0) return false;
	if(s<=9&&s>=1 && m>=2&& pos){
		ans2[m-1]='0';
		return helper2(s-0,m-1,ans2,pos);
	}
	if(m==1&&s<=9&&s>=0) {
		ans2[m-1]=(char)(s+48);
		return true;
	}
	for(i=9;i>=0;i--){
		ans2[m-1]=(char)(i+48);
		if(i!=0) pos = true;
		bool cond = helper2(s-i,m-1,ans2,pos);
		if(cond) break;
	}
	return true;
}
* */
string findMin(int s,int d){
    string st = "";
    int i;
    for(i=d;i>1;i--){
        if(s>9){
            st = (char)(9+'0')+st;
            s-=9;
        }else {
            st = (char)('0'+s-1)+st;
            s-=(s-1);
        }
    }
    st=(char)(s+'0')+st;
    return st;
}
int main(){
	ll m,s;
	cin>>m>>s;
	char ans[m+1],ans2[m+1];
	if(s>9*m || (s==0&&m>1)){
		cout<<"-1 -1";
		return 0;
	}
	helper(s,m,ans);
	ans[m]='\0';
	if(m>=2 && ans[0]=='0') {
		cout<<"-1 -1";
		return 0;
	}
	//helper2(s,m,ans2,false);
	//ans2[m]='\0';
	cout<<findMin(s,m)<<" "<<ans;
	return 0;
}
//submitted
