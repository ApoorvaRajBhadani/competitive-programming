#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

void printfromhome(){
	cout<<2<<" "<<2<<"\n";
	cout<<1<<" "<<3<<"\n";
	cout<<3<<" "<<1<<"\n";
	cout<<2<<" "<<2<<"\n";
	cout<<3<<" "<<3<<"\n";
	cout<<1<<" "<<5<<"\n";
	cout<<5<<" "<<1<<"\n";
	cout<<3<<" "<<3<<"\n";
	cout<<4<<" "<<4<<"\n";
	cout<<7<<" "<<1<<"\n";
	cout<<1<<" "<<7<<"\n";
	cout<<4<<" "<<4<<"\n";
	cout<<5<<" "<<5<<"\n";
	cout<<2<<" "<<8<<"\n";
	cout<<8<<" "<<2<<"\n";
	cout<<5<<" "<<5<<"\n";
	cout<<6<<" "<<6<<"\n";
	cout<<4<<" "<<8<<"\n";
	cout<<8<<" "<<4<<"\n";
	cout<<6<<" "<<6<<"\n";
	cout<<7<<" "<<7<<"\n";
	cout<<6<<" "<<8<<"\n";
	cout<<8<<" "<<6<<"\n";
	cout<<7<<" "<<7<<"\n";
	cout<<8<<" "<<8<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int r0,c0,c=0;
		cin>>r0>>c0;
		//if already on 1,1
		if(r0==1&&c0==1){
			cout<<"25\n";
			printfromhome();
		}else if(r0==c0){
			//on diagonal
			cout<<"26\n";
			cout<<1<<" "<<1<<"\n";
			printfromhome();
		}else{
			//not on diagonal
			int dgc = (r0+c0)/2;
			cout<<"27\n";
			cout<<dgc<<" "<<dgc<<"\n";
			cout<<1<<" "<<1<<"\n";
			printfromhome();
		}
	}
	return 0;
}
