#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ll i,h,n,a,b,k,p=0,t;
	cin>>n>>a>>b>>k;
	vector<ll> v;
	for(i=0;i<n;i++){
		cin>>h;
		t = h%(a+b);
		if(t>0&&t<=a){
			//can be defeated
			p++;
		}else if(t==0){
			v.push_back(a+b-a);
			//just left by oponent
		}else if(t>a){
			v.push_back(t-a);
		}
	}
	//cout<<p<<endl;
	sort(v.begin(),v.end());
	for(i=0;i<v.size()&&k>0;i++){
		if(v[i]%a==0){
			//k req is v[i]/a
			if(k>=v[i]/a){
				k-=v[i]/a;
				p++;
			}
			else{
				break;
			}
		}else{
			//k req is v[i]/a + 1
			if(k >= v[i]/a + 1){
				k-=v[i]/a+1;
				p++;
			}else{
				break;
			}
		}
	}
	cout<<p<<endl;
	return 0;
}
