#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e) for(i=s;i<=e;i++)
//#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))

void solve(){
	ll i,j,n;
	string s;
	cin>>s;
	n = s.size();
	if(n==1||n==2){
		cout<<0<<endl;
		cout<<""<<endl;
		return;
	}
	set<ll> st;
	vector<bool> kut(n,false);
	for(i=2;i<n;i++){
		//cout<<i<<endl;
		if(s[i-2]=='o' && s[i-1]=='n' && s[i]=='e'){
			if(kut[i-2])continue;
			else{
				st.insert(i-1);
				kut[i-1]=true;
			}
		}else if(s[i-2]=='t' && s[i-1]=='w' && s[i]=='o'){
			if(i+2<n){
				if(s[i+1]=='n' &&s[i+2]=='e') {
					st.insert(i);
					kut[i]=true;
				}else{
					st.insert(i-1);
					kut[i-1]=true;
				}
			}else{
				st.insert(i-1);
				kut[i-1]=true;
			}
		}
	}
	cout<<st.size()<<endl;
	for(auto it=st.begin();it!=st.end();it++){
		cout<<*it +1<<" ";
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	while(t--){
		solve();
	}
	return 0;
}
