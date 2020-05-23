#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll x,y,i,j;
	cin>>x>>y;
	if((abs(x)+abs(y))%2==0){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	cout<<x<<" "<<y<<" ";
	ll mypow = log2((double)(abs(x)+abs(y)));
	vector<ll> nums;
	for(i=0;i<(mypow+1);i++){
		nums.push_back((1<<i));
	}
	ll diff = pow(2,mypow+1) -1 -(abs(x)+abs(y));
	for(i=nums.size()-1;i>=0;i--){
		if((2*nums[i]) <= diff){
			diff-=(2*nums[i]);
			nums[i] = -1 * nums[i];
		}
	}
	vector<bool> dir;
	ll xcop=abs(x),ycop=abs(y);
	for(i=0;i<nums.size();i++){
		ll virnum = (nums[i]/(1<<i));
		if(((xcop)%2)==1){
			dir.push_back(true);
			xcop-=virnum;
		}else{
			dir.push_back(false);
			ycop-=virnum;
		}
		xcop/=2;
		ycop/=2;
	}
	string ans = "";
	for(i=0;i<nums.size();i++){
		if(dir[i]){
			//x is pos
			if(x>0){
			if(nums[i]>0){
				ans+='E';
			}else{
				ans+='W';
			}
			}
			//x is neg
			else{
			if(nums[i]>0){
				ans+='W';
			}else{
				ans+='E';
			}
			}
		}else{
			//y is pos
			if(y>0){
			if(nums[i]>0){
				ans+='N';
			}else{
				ans+='S';
			}
			}
			//y is neg
			else{
			if(nums[i]>0){
				ans+='S';
			}else{
				ans+='N';
			}
			}
		}
	}
	nums.clear();
	dir.clear();
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}













