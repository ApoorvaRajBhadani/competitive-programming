#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void update(int index,int value,int* BIT,int n){
	for(;index<=n;index+= index&(-index)){
		BIT[index]+=value;
	}
}
int query(int index,int* BIT){
	int sum=0;
	for(;index>0;index-=index&(-index)){
		sum+=BIT[index];
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	int* arr = new int[n+1]();
	int* BIT = new int[n+1]();
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		update(i,arr[i],BIT,n);
	}
	cout<<"sum of first 5 elements is "<<query(5,BIT)<<endl;
	cout<<"sum from 2nd to 6th idx is "<<query(6,BIT)-query(1,BIT)<<endl;
	return 0;
}
