#include<iostream>
using namespace std;

int bakchodi(){
	return 5;
}
//template <typename q>
template <typename t,typename q>
q mymax(t x,t y){
	return (x>y)?x:y;
}
int main(){
	cout<<mymax<int,char>(3,5)<<endl;
	cout << mymax<double,double>(3.0, 7.0) << endl; // call myMax for double 
  cout << mymax<char,int>('g', 'e') << endl;   // call myMax for char 
  
  return 0; 
}