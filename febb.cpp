#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ll t,n,m,i,l,r,prev,j;
	cin>>t;
	while(t--){
		cin>>n>>m;
		bool flag = true;
		ll a[n],p[m],ac[n],c[n],k;
		for(i=0;i<n;i++){
			cin>>a[i];
			ac[i]=a[i];
			c[i]=1;
		}
		for(i=0;i<m;i++){
			cin>>p[i];
		}
		sort(ac,ac+n);
		sort(p,p+m);
		prev=p[0];
		l=prev-1;
		k=1;
		for(i=1;k;i++){
			if(i==m){ k=0;r=prev;}
			else {if((p[i]+1)==prev) 
			{prev = p[i];continue;}
			else {
				r = prev+1-1;
			}
		}
		cout<<l<<" "<<r<<endl;
			ll fa[100]={0},fac[100]={0};
			for(j=l;j<=r;j++){
				fa[a[j]-1]++;
				fac[ac[j]-1]++;
			}
			for(j=0;j<100;j++){
				if(fa[j]!=fac[j]) break;
			}
			if(j==100) { 
				for(j=l;j<=r;j++){
				c[j]=1;
			}
			}else{
				flag = false;
				break;
			}
			if(k!=0)prev = p[i];
		}
		if(flag==false){
			cout<<"NO"<<endl;
		}else{
			for(i=0;i<n;i++){
				if(c[i]==0){
					if(a[i]!=ac[i]) break;
				}
			}
			if(i==n) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
