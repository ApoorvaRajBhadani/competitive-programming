#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
unsigned long long int pow222[65];
void precompute(){
	for(ll i=0;i<=64;i++){
		pow222[i] = pow(2,i);
	}
}
ll F(ll x,ll y,ll k){
	return ((x&k)*(y&k));
}
unsigned long long int minToAdd(unsigned long long int freekamaal,unsigned long long int diff){
	bitset<65> FFF(freekamaal);
	ll i;
	unsigned long long int ans=0,ans2=0,pwr=0,pseudonum=0;
	for(i=64;i>=0;i--){
		if(FFF.test(i)){
			unsigned long long int val = pow222[i];
			if(val<=diff){
				diff-=val;
				ans+=val;
			}
		}
	}
	if(diff==0) return ans;
	bitset<65> AAA(ans);
	for(i=0;i<=64;i++){
		if(FFF.test(i)){
			if(AAA.test(i)){
				pseudonum+=pow222[pwr];
			}
			pwr++;
		}
	}
	pseudonum++;
	vector<unsigned long long int> wgt;
	for(i=0;i<=64;i++){
		if(FFF.test(i)) wgt.push_back(pow222[i]);
	}
	bitset<65> BBB(pseudonum);
	for(i=0;i<=64;i++){
		if(BBB.test(i)){
			ans2+=wgt[i];
		}
	}
	return ans2;
}
void solve(){
	ll i;
	unsigned long long int x,y,l,r;
	cin>>x>>y>>l>>r;
	if(l==r){
		cout<<l<<endl;
		return;
	}
	unsigned long long int a = x|y;
	unsigned long long int shuruidharse = (ll)log2(a) +1;
	unsigned long long int maxinhand = pow222[shuruidharse]-1;
	while(maxinhand<l){
		a+= pow222[shuruidharse];
		maxinhand+=pow222[shuruidharse];
	}
	unsigned long long int freekamaal = ~a;
	bitset<65> FFF(freekamaal);
	//cout<<"freekamaal is "<<FFF<<endl;
	bitset<65> R(r),A(a);
	vector<ll> kvec;
	ll countr=0,counta=0;
	for(i=64;i>=0;i--){
		if(R.test(i)){
			countr++;
		}
		if(A.test(i)){
			counta++;
		}
		if(countr>counta){
			kvec.push_back(a);
			//break;
			a+=pow222[i];
			counta++;
		}else if(countr==counta){
			if(A.test(i)) kvec.push_back(a-pow222[i]);
		}else if(counta>countr){
			a-=pow222[i];
			counta--;
		}
	}
	kvec.push_back(a);
	ll z=l,Fmax = LLONG_MIN;
	for(i=0;i<kvec.size();i++){
		bitset<65> bt(kvec[i]);
		//cout<<bt<<endl;
		if(kvec[i]<l){
			unsigned long long int diff = l-kvec[i];
			unsigned long long int mintoadd = minToAdd(freekamaal,diff);
			//cout<<kvec[i]<<"->>"<<kvec[i]+mintoadd<<endl;
			if(kvec[i]+mintoadd>=l &&kvec[i]+mintoadd<=r){
				kvec[i]+=mintoadd;
			}else continue;
		}
		ll myF = F(x,y,kvec[i]);
		if(myF>Fmax){
			Fmax = myF;
			z = kvec[i];
		}else if(myF==Fmax){
			z = min(z,kvec[i]);
		}
	}
	if(Fmax == 0) z = l;
	cout<<z<<endl;
	//cout<<z<<" giving "<<Fmax<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	precompute();
	ll t;
	cin>>t;
	while(t--) {
		//cout<<"---------------------------"<<endl;
		solve();
	}
	return 0;
}
