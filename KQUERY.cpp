#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MAX 1000000001
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
class Query{
	public:
	ll s,e,val,idx;
};
class Rquer{
	public:
	ll idx,val,upto;
	bool type;//0-start 1-end
};
bool compare(Rquer a,Rquer b){
	return a.upto<b.upto;
}
void update(ll* bit,ll i,ll n){
	for(;i<=n;i+=(i&(-i))){
		bit[i]++;
	}
}
ll query(ll* bit,ll i){
	ll sum=0;
	for(;i>0;i-=(i&(-i))){
		sum+=bit[i];
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll q,i,n,j;
	cin>>n;
	ll arr[n+1];
	vector<ll> sarr;
	arr[0]=0;
	for(i=1;i<=n;i++){
		cin>>arr[i];
		sarr.push_back(arr[i]);
	}
	cin>>q;
	Query qarr[q];
	ll* ans = new ll[q]();
	vector<Rquer> rqarr;
	for(i=0;i<q;i++){
		cin>>qarr[i].s>>qarr[i].e>>qarr[i].val;
		//qarr[i].val = mp[qarr[i].val];
		sarr.push_back(qarr[i].val);
		qarr[i].idx =i;
		Rquer rquer = {0,0,0,0};
		rquer.idx=i;
		rquer.val=qarr[i].val;
		rquer.upto = qarr[i].s-1;
		rquer.type=0;
		Rquer rquer2 = {0,0,0,0};
		rquer2.idx=i;
		rquer2.val=qarr[i].val;
		rquer2.upto = qarr[i].e;
		rquer2.type=1;
		if(rquer.upto!=0)rqarr.push_back(rquer);
		rqarr.push_back(rquer2);
	}
	sort(sarr.begin(),sarr.end());
	map<ll,ll> mp;
	j=1;
	for(i=0;i<sarr.size();i++){
		if(!mp[sarr[i]]){
			mp[sarr[i]]=j++;
			//cout<<sarr[i]<<" is now "<<mp[sarr[i]]<<endl;
		}
	}
	ll* bit = new ll[mp.size()+1]();
	sort(rqarr.begin(),rqarr.end(),compare);
	memset(bit,0,sizeof(bit));
	j=0;
	for(i=1;i<=n;i++){
		update(bit,mp[arr[i]],mp.size());
		//cout<<mp[arr[i]]<<" updated\n";
		while(j<rqarr.size() && rqarr[j].upto==i){
			//cout<<rqarr[j].type<<" "<<rqarr[j].upto<<" "<<rqarr[j].val<<" "<<rqarr[j].idx<<endl;
			if(rqarr[j].type==0){
				ans[rqarr[j].idx]-=(i-query(bit,mp[rqarr[j].val]));
				
			}else{
				ans[rqarr[j].idx]+=(i-query(bit,mp[rqarr[j].val]));
				
			}
			j++;
		}
	}
	for(i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}















