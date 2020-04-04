#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll highestPowerof2(ll n) 
{ 
   ll p = (ll)log2(n); 
   return (ll)pow(2, p);  
} 
  
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll u,v;
	cin>>u>>v;
	if(u==0&&v==0) {
		cout<<0;
		return 0;
	}
	if(u>v){
		cout<<-1;
		return 0;
	}
	//if u<=v
	if(u==v){
		cout<<1<<endl<<u;
		return 0;
	}
	if((v-u)%2==1) {
		cout<<-1;
		return 0;
	}
	ll man=0,ans=0,p=highestPowerof2(u),pp;
	pp=p;
	ll timex = v/u;
	if(timex%2==0) timex-=1;
	man=timex*u;
	v-=man;
	while(v>0){
		ll times = v/(2*p);
		if(times>0){
			v-=(times*2*p);
			ans+= p*times;
		}
		//if(2*p <= v){
		//	v-=(2*p);
		//	ans+=p;
		//}
		else{
			p= p>>1;
		}
	}
	if(pp*2-1  >= man+ans){
		cout<<2<<endl;
		cout<<man+ans<<" "<<ans;
	}else{
		cout<<3<<endl;
		cout<<man<<" "<<ans<<" "<<ans;
	}
	return 0;
}
