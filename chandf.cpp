#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
#define MBITS 42
void solve(){
	ll x,y,l,r,a,b,c,d,e,f,k=0,i,j,vleft;
	cin>>x>>y>>l>>r;
	a = x|y;
	b = x&y;
	c = x^y;
	d = x&c;
	e = y&c;
	f = ~a;
	vleft = r;
	bitset<MBITS> X(x),Y(y),A(a),B(b),C(c),D(d),E(e),F(f);
	//taking max out of b
	//step_1
	//for(i=41;i>=0;i--){
		//if(B.test(i)){
			//ll val = pow(2,i);
			//if(val<=vleft){
				//vleft-=val;
				//k+=val;
			//}
		//}
	//}
	ll dsum[42],esum[42];
	dsum[0] = D[0];
	esum[0] = E[0];
	for(i=1;i<=41;i++){
		dsum[i]=dsum[i-1];
		if(D.test(i)) dsum[i]+=pow(2,i);
		esum[i]=esum[i-1];
		if(E.test(i)) esum[i]+=pow(2,i);
	}
	//step_2
	for(i=41;i>=0;i--){
		if(D.test(i)){
			ll sum = pow(2,i) + esum[i];
			if(sum<=vleft){
				vleft-=sum;
				k+=sum;
				//step_3
				for(i=i-1;i>=0;i--){
					if(D.test(i)){
						ll val = pow(2,i);
						if(val<=vleft){
							vleft-=val;
							k+=val;
						}
					}
					if(B.test(i)){
						ll val = pow(2,i);
						if(val<=vleft){
							vleft-=val;
							k+=val;
						}
					}
				}
				//step3done
			}
		}else if(E.test(i)){
			ll sum = pow(2,i) + dsum[i];
			if(sum<=vleft){
				vleft-=sum;
				k+=sum;
				//step_3
				for(i=i-1;i>=0;i--){
					if(E.test(i)){
						ll val = pow(2,i);
						if(val<=vleft){
							vleft-=val;
							k+=val;
						}
					}
					if(B.test(i)){
						ll val = pow(2,i);
						if(val<=vleft){
							vleft-=val;
							k+=val;
						}
					}
				}
				//step3done
			}
		}
	}
	//for(i=41;i>=0;i--){
		//if(B.test(i)){
			//ll val = pow(2,i);
			//if(val<=vleft){
				//vleft-=val;
				//k+=val;
			//}
		//}
	//}
	cout<<"-------------------"<<endl;
	cout<<"x is "<<x<<endl;
	cout<<"y is "<<y<<endl;
	cout<<"z chosen is "<<k<<" in "<<l<<" to "<<r<<endl;
	cout<<"F is " <<(x&k)*(y&k)<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--) solve();
	return 0;
}







