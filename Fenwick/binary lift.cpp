#include<bits/stdc++.h> 
using namespace std;
typedef int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
ll binarylift(ll val,ll* fen,ll n){
	ll curr=0,prevsum=0,i;
	for(i=log2(n);i>=0;i--){
		if(curr+(1<<i) <=n){
			if(prevsum + fen[curr+(1<<i)]<val){
				curr+=(1<<i);
				prevsum+=fen[curr];
			}
		}
	}
	return curr+1;
}
void update(ll index,ll val,ll* fen,ll n){
	for(;index<=n;index+=index&(-index)){
		fen[index]+=val;
	}
}
ll query(ll index,ll* fen){
	ll sum=0;
	for(;index>0;index-=index&(-index)){
		sum+=fen[index];
	}
	return sum;
}
void solve(){
	ll i,j,n,q,k;
	cin>>n>>q;
	ll* arr = new ll[n+1]();
	ll* fen = new ll[n+1]();
	for(i=0;i<n;i++){
		cin>>arr[i];
		update(arr[i],1,fen,n);
	}
	while(q--){
		cin>>k;
		if(k<0){
			k=-k;
			//remove the k-th smallest number from multiset
			//i.e. find the smallest prefix sum >= k
			//at that point reduce by 1
			//binary search
			//this is method 1
			//ll l=1,r=n;
			//while(l<r){
				//ll mid = (l+r)/2;
				//ll val = query(mid,fen);
				//if(k<=val){
					//r=mid;
				//}else{
					//l=mid+1;
				//}
			//}
			//update(l,-1,fen,n);
			//method 2 binary lifting
			//finding the point at which prefix sum is less than req
			//and that value is maximum possible
			ll bl = binarylift(k,fen,n);
			update(bl,-1,fen,n);
		}else{
			//add number k
			update(k,1,fen,n);
		}
	}
	if(query(n,fen)==0){
		cout<<0<<endl;
	}else{
		for(i=1;i<=n;i++){
			if(query(i,fen)>0){
				cout<<i<<endl;
				return;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
