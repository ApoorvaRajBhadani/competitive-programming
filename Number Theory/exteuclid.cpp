#include<bits/stdc++.h> 
using namespace std;
class Triplet{
	public:
		int x,y,g;
};
Triplet extendedEuclid(int a,int b){
	//Base Case
	if(b==0){
		Triplet myAns;
		myAns.g = a;
		myAns.x = 1;
		myAns.y = 0;//y can be anything,taking 0,i.e infinite solutions exist
		return myAns;
	}
	//Applying Ext Euclid
	Triplet smallAns = extendedEuclid(b,a%b);
	Triplet myAns;
	myAns.g = smallAns.g;
	myAns.x = smallAns.y;
	myAns.y = smallAns.x - (a/b)*smallAns.y;
	return myAns;
}
int main(){
	int a,b;
	cin>>a>>b;
	Triplet exteuc = extendedEuclid(a,b);
	cout<<"gcd is "<<exteuc.g<<endl;
	cout<<"xg is "<<exteuc.x<<endl;
	cout<<"yg is "<<exteuc.y<<endl;
	return 0;
}
