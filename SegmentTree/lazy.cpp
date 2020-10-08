#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define setbits(x) __builtin_popcountll(x)
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 200000
//https://codeforces.com/contest/52/problem/C
ll arr[MAXN+5];
ll tree[4*MAXN+5];
ll ltree[4*MAXN+5];
struct spaces{
	int f=-1,s=-1;
};
spaces thequery(string s){
	ll i;
	spaces mys;
	fo(i,0,s.size()){
		if(s[i]==' '){
			if(mys.f==-1) mys.f=i;
			else mys.s=i;
		}
	}
	return mys;
}
void buildTree(ll s,ll e,ll ni){
	if(s==e){
		tree[ni]=arr[s];//same as arr[e]
		return;
	}
	ll m = s +(e-s)/2;
	buildTree(s,m,ni*2);
	buildTree(m+1,e,ni*2+1);
	tree[ni] = min(tree[ni*2],tree[ni*2+1]);
}
void updTree(ll s,ll e,ll ni,ll l,ll r,ll v){
	//invalid case,(not necessary)
	if(s>e) return;
	//update lazy values
	if(ltree[ni]!=0){
		tree[ni]+=ltree[ni];
		if(s!=e){
			ltree[2*ni]+=ltree[ni];
			ltree[2*ni+1]+=ltree[ni];
		}
		ltree[ni]=0;
	}
	//no overlap
	if(l>e || r<s){
		return;
	}
	//complete overlap
	if(s>=l && e<=r){
		tree[ni]+=v;
		if(s!=e){
			ltree[ni*2]+=v;
			ltree[ni*2+1]+=v;
		}
		return;
	}
	//partial overlap
	ll m = s + (e-s)/2;
	updTree(s,m,ni*2,l,r,v);
	updTree(m+1,e,ni*2+1,l,r,v);
	tree[ni] = min(tree[ni*2],tree[ni*2+1]);
}
ll queryTree(ll s,ll e,ll ni,ll l,ll r){
	//invalid case,(not necessary)
	if(s>e) return INT_MAX;
	//update lazy values
	if(ltree[ni]!=0){
		tree[ni]+=ltree[ni];
		if(s!=e){
			ltree[ni*2]+=ltree[ni];
			ltree[ni*2+1]+=ltree[ni];
		}
		ltree[ni]=0;
	}
	//no overlap
	if(s>r || e<l){
		return INT_MAX;
	}
	//complete overlap
	if(s>=l && e<=r){
		return tree[ni];
	}
	//partial overlap
	ll m = s + (e-s)/2;
	ll lt = queryTree(s,m,ni*2,l,r);
	ll rt = queryTree(m+1,e,ni*2+1,l,r);
	return min(lt,rt);
}
void solve(ll caseno){
	ll i,j,n,m;
	cin>>n;
	fo(i,0,n) cin>>arr[i];
	buildTree(0,n-1,1);
	mset(ltree,0);//initialize lazy tree with 0
	cin>>m;
	string s;getline(cin,s);
	fo(i,0,m){
		getline(cin,s);
		spaces mys = thequery(s);
		if(mys.s==-1){
			//rmq
			ll lf = stoi(s.substr(0,mys.f));
			ll rg = stoi(s.substr(mys.f+1));
			if(lf<=rg){
				cout<<queryTree(0,n-1,1,lf,rg)<<endl;
			}else{
				cout<<min(queryTree(0,n-1,1,lf,n-1),queryTree(0,n-1,1,0,rg))<<endl;
			}
		}else{
			//inc
			ll lf = stoi(s.substr(0,mys.f));
			ll rg = stoi(s.substr(mys.f+1,mys.s-mys.f-1));
			ll v = stoi(s.substr(mys.s+1));
			if(lf<=rg){
				updTree(0,n-1,1,lf,rg,v);
			}else{
				updTree(0,n-1,1,lf,n-1,v);
				updTree(0,n-1,1,0,rg,v);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
