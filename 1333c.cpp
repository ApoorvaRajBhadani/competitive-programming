#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,i,a,ans=0,j;
	cin>>n;
	ans = (n * (n+1))/2;
	vector<ll> vec;
	ll sa[n+1],sum=0;
	sa[0]=sum;
	map<ll,vector<ll>> lastcame;
	map<ll,ll> lastcametimes;
	ll lastcamenum[n+1];
	lastcame[sum].push_back(0);
	map<ll,bool> numcame,invalidpts;j=0;
	lastcametimes[sum]++;
	for(i=0;i<n;i++){
		cin>>a;
		if(numcame[a]){
			ans+=(j*(j+1))/2;
			invalidpts[i+1]=true;
			j++;
		}
		else{
			ans-=(j*(j+1))/2;
			j=0;
		}
		numcame[a]=1;
		sum+=a;
		sa[i+1]=sum;
		lastcamenum[i+1] = lastcametimes[sum];
		if(invalidpts[i+1]) lastcame[sum].push_back(i+1);
		if(!invalidpts[i+1])lastcametimes[sum]++;
		vec.push_back(a);
	}
	ans-=(j*(j+1))/2;
			j=0;
			//cout<<ans<<endl;
	set<vector<ll>> st;
	//fo(i,0,n) cout<<sa[i]<<" ";
	//cout<<endl;
	for(i=1;i<=n;i++){
		sum = sa[i];
		//cout<<"r by "<<lastcamenum[i]<<endl;
		ans-=lastcamenum[i];
		//if(lastcame[sum].size()>0){
			//ll count =0;
			//if(invalidpts[i])
			//for(auto it=lastcame[sum].begin();it!=lastcame[sum].end();it++){
				//if(invalidpts[*it+1]) count++;
			//}
			//ans+=count;
		//}
	}
	cout<<ans<<endl;
	return 0;
}















