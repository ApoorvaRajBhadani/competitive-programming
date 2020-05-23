#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
class ques{
	public:
	char type;
	ll val;
};
void update(ll* bit,ll idx,ll val,ll n){
    for(;idx<=n;idx += (idx&(-idx))){
        bit[idx]++;
    }
}
ll query(ll* bit,ll idx){
    ll sum=0;
    for(;idx>0;idx-= (idx&(-idx))){
        sum+=bit[idx];
    }
    return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll q,i,j;
	cin>>q;
	ques qarr[q];
	set<ll> sarr;
    vector<ll> arr;
	for(i=0;i<q;i++){
		cin>>qarr[i].type>>qarr[i].val;
		if(qarr[i].type == 'D'||qarr[i].type=='I'){
            //arr.push_back(qarr[i].val);
			sarr.insert(qarr[i].val);
		}
	}
    for(auto it = sarr.begin();it!=sarr.end();it++){
        //cout<<*it<<endl;
        arr.push_back(*it);
    }
	sort(arr.begin(),arr.end());
	map<ll,ll> mp;
	for(i=0;i<arr.size();i++){
		mp[arr[i]]=i+1;
	}
    ll* bit = new ll[arr.size()]();
	for(i=0;i<q;i++){
		char type = qarr[i].type;
		ll val = qarr[i].val;
		if(type=='I'){
				if(query(bit,mp[val]) == query(bit,mp[val]-1)){
                    cout<<"inserted "<<val<<endl;
            	    update(bit,mp[val],1,arr.size());
            	}
        }else if(type=='D'){
                if(query(bit,mp[val]) != query(bit,mp[val]-1)){
					cout<<"deleted "<<val<<endl;
                    update(bit,mp[val],-1,arr.size());
                }
        }else if(type=='C'){
            	ll idx = lower_bound(arr.begin(),arr.end(),val) -arr.begin();
                cout<<query(bit,mp[arr[idx-1]])<<endl;
        }else if(type=='K'){
                for(j=0;j<arr.size();j++){
					if(query(bit,mp[arr[j]] ) ==val){
						cout<<arr[j]<<endl;
						break;
					}
				}
				if(j==arr.size()){
					cout<<"invalid"<<endl;
				}
		}
	}
	return 0;
}

















