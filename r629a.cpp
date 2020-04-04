#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
void solve(){
	ll n,i,t,k=1,prev,lastch,kno=1;string ans="";
	cin>>n;
	vector<ll> vec;
	set<ll> st;
	for(i=0;i<n;i++){
		cin>>t;
		vec.push_back(t);
		st.insert(t);
	}
	if(st.size()==1){
		//cout<<"case 1\n";
		cout<<1<<endl;
		for(i=0;i<n;i++) cout<<"1 ";
		cout<<endl;
	}else{
		if(n%2==0){
			//cout<<"case2even\n";
			cout<<2<<endl;
			for(i=0;i<n;i++) cout<<(i%2?2:1)<<" ";
			cout<<endl;
		}else{
			bool mila=false;
			prev=vec[0];
			string colors="1";
			k=1;
			for(i=1;i<n;i++){
				if(!mila){
					if(prev==vec[i]){
						mila=true;
						colors+=(char)(k+'0');
					}
					else{
						if(k==1) k=2;
					else if(k==2) k=1;
					colors+=(char)(k+'0');
					}
				}else{
					if(k==1) k=2;
					else if(k==2) k=1;
					colors+=(char)(k+'0');
				}
				prev=vec[i];
			}
			if(!mila){
				//cout<<"case2oddnhimila\n";
				if(vec[0]==vec[n-1]){
					cout<<2<<endl;
					for(i=0;i<n;i++) cout<<colors[i]<<" ";
					cout<<endl;
				}else{
					cout<<3<<endl;
					for(i=0;i<n-1;i++) cout<<colors[i]<<" ";
					cout<<3<<endl;
				}
			}else{
				//cout<<"case2oddmila\n";
				cout<<2<<endl;
				for(i=0;i<n;i++) cout<<colors[i]<<" ";
				cout<<endl;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
