#include<bits/stdc++.h>
using namespace std;
int main(){
int t,l;
cin>>t;
while(t--){
string s;
cin>>s;
l=s.size();
if(l<=10){
cout<<s<<endl;
}
else{
cout<<s[0]<<l-2<<s[l-1]<<endl;
}
}
return 0;
}
