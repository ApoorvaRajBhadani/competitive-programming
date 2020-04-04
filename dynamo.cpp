#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ll t,n,a,s,c,b,d,e,v,mx;
    cin>>t;
    while(t--){
        cin>>n;
	mx=pow(10,n);
        cin>>a;
        s=a;
	s+=mx;
	s+=mx;
        cout<<s;
        //fflush(stdout);
        cout<<endl;
        cin>>b;
	c=0;
	c-=b;
	c+=mx;
        cout<<c;
        //fflush(stdout);
        cout<<endl;
         cin>>d;
	e=0;
	e-=d;
	e+=mx;
	cout<<e;
        //fflush(stdout);
        cout<<endl;
        cin>>v;
        if(v==-1) break;
        //fflush(stdout);
   	cout<<endl;
    }
	return 0;
}
