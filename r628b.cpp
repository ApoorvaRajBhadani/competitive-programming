#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n,num;
		cin>>n;
		set<ll> st;
		for(int i=0;i<n;i++){
			cin>>num;
			st.insert(num);
		}
		cout<<st.size()<<endl;
	}
	return 0;
}
