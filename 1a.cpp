#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,a;
cin>>n>>m>>a;
double na,ma;
na = (double)n/a;
if(na-(int)na!=0) na=ceil(na);
ma = (double)m/a;
if(ma-(int)ma!=0) ma=ceil(ma);
long long int ans = na*ma;
cout<<ans;
return 0;
}
