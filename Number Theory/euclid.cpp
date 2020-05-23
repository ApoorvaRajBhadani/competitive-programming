#include<bits/stdc++.h> 
using namespace std;
int gcd_euclid(int a,int b){
	if(b==0) return a;
	return gcd_euclid(b,a%b);
}
int main(){
	int a,b;
	cin>>a>>b;//a and b >0
	cout<<gcd_euclid(a,b)<<endl;
	return 0;
}
