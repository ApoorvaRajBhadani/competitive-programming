#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ll t;
	cin>>t;
	ll n,m,i,l,r,prev,ii,j;
	while(t--){
		cin>>n>>m;
		ll arr[n],arrc[n],pos[m+1],c[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
			arrc[i]=arr[i];
			c[i]=0;
		}
		for(i=0;i<m;i++){
			cin>>pos[i];
			pos[i]-=1;
		}
		bool flag = true;
		sort(arrc,arrc+n);
		sort(pos,pos+m);
		pos[m]=0;
		l=pos[0];
		r=pos[0]+1;
		prev = pos[0];
		for(i=1;i<m+1&&flag;i++){
			if(pos[i]==prev+1){
				r=pos[i]+1;
			}else{
				//check
				ll farr[100]={0},farrc[100]={0};
				for(j=l;j<=r;j++){
					farr[arr[j]-1]++;
					farrc[arrc[j]-1]++;
				}
				for(j=0;j<100;j++){
					if(farr[j]!=farrc[j]) break;
				}
				if(j==100){
					for(j=l;j<=r;j++){
						c[j]=1;
					}
				}else{
					flag = false;
				}
				l = pos[i];
				r = pos[i]+1;
			}
			prev = pos[i];
		}
		for(i=0;i<n&&flag;i++){
			if(c[i]==0){
				if(arr[i]!=arrc[i]){
					flag = false;
					break;
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
