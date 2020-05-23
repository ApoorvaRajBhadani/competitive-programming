#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
class Triplet{
	public:
	int g,x,y;
};
Triplet exteuc(int a,int b){
	if(b==0){
		Triplet myans;
		myans.g = a;
		myans.x = 1;
		myans.y = 0;
		return myans;
	}
	Triplet smallans = exteuc(b,a%b);
	Triplet myans;
	myans.g = smallans.g;
	myans.x = smallans.y;
	myans.y = smallans.x - (a/b)*smallans.y;
	return myans;
}
int mminv(int a,int m){
	Triplet ggg = exteuc(a,m);
	int x = ggg.x;
	int result = (x%m + m)%m;
	return result;
}
int findminx(int num[],int rem[],int k){
	int i,prod = 1;
	for(i=0;i<k;i++) prod*=num[i];
	int result = 0;
	for(i=0;i<k;i++){
		int pp = prod/num[i];
		result = (result + (rem[i]*pp* mminv(pp,num[i]) )%prod  )%prod;
	}
	return result;
}
int main(){
	int num[]={5,7};
	int rem[]={1,3};
	int k = sizeof(num)/sizeof(num[0]);
	cout<<"x is "<<findminx(num,rem,k)<<endl;
	return 0;
}
