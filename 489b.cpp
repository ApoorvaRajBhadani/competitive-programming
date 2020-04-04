#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	int n,m,i,t,c=0;
	cin>>n;
	int a[102]={0};
	for(i=0;i<n;i++){
		cin>>t;
		a[t]++;
	}
	cin>>m;
	int b[m];
	for(i=0;i<m;i++){
		cin>>b[i];
	}
	vector<int> mono,duo,trio;
	for(i=0;i<m;i++){
		int left=0,mid=0,right=0;
		if(a[b[i]]>0) mid=1;
		if(a[b[i]-1]>0) left =1;
		if(a[b[i]+1]>0) right =1;
		//cout<<mid+left+right<<endl;
		if((left+right+mid)==1) mono.push_back(b[i]);
		else if((left+right+mid)==2) duo.push_back(b[i]);
		else if((left+right+mid)==3) trio.push_back(b[i]);
	}
	for(auto it=mono.begin();it!=mono.end();it++){
		if(a[*it]>0){
		a[*it]--;c++;
		}
		else if(a[(*it) -1]>0){
		a[(*it) -1]--;c++;
		}
		else if(a[(*it)+1]>0){
		a[(*it)+1]--;c++;
		}
	}
	for(auto it=duo.begin();it!=duo.end();it++){
		//cout<<*it<<endl;
		if(a[*it]>0){
		a[*it]--;c++;
		}
		else if(a[(*it) -1]>0){
		a[(*it) -1]--;c++;
		}
		else if(a[(*it)+1]>0){
		a[(*it)+1]--;c++;
		}
	}
	for(auto it=trio.begin();it!=trio.end();it++){
		if(a[*it]>0){
		a[*it]--;c++;
		}
		else if(a[(*it) -1]>0){
		a[(*it) -1]--;c++;
		}
		else if(a[(*it)+1]>0){
		a[(*it)+1]--;c++;
		}
	}
	cout<<c;
return 0;
}
