#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
struct tree{
	ll x,h;
};
int main(){
	ll n,i;
	cin>>n;
	tree a[n];
	for(i=0;i<n;i++){
		cin>>a[i].x>>a[i].h;
	}
	ll upto=INT_MIN,c=0;
	for(i=0;i<n-1;i++){
		//try left
		if(a[i].x-a[i].h > upto){
			//cut
			c++;
			upto = a[i].x;
		}
		//try right
		else if(a[i].x+a[i].h<a[i+1].x){
			//cut
			c++;
			upto = a[i].x+a[i].h;
		}
		//no cut
		else upto = a[i].x;
	}
	c++;
	cout<<c;
	return 0;
}
