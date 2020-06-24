#include<bits/stdc++.h> 
using   namespace std;
typedef long long int ll;
#define fo(i,s,e) for(i=s;i<=e;i++)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))

void solve(){
	ll i,j,n,m;
	cin>>n>>m;
	string s[n],ans="";
	fo(i,0,n-1) cin>>s[i];
	vector<bool> alive(n,true);
	fo(i,0,m-1){
		map<char,vector<ll>> mp;
		fo(j,0,n-1){
			char ccc = s[j][i];
			mp[ccc].pbb(j);
		}
		char ch='#';
		map<ll,vector<char>> mp2;
		for(auto it = mp.begin();it!=mp.end();it++){
			mp2[it->second.size()].pbb(it->first);
		}
		for(j=10;j>=0;j--){
			if(mp2[j].size()>0){
				if(mp2[j].size()==1){
					ch = mp2[j][0];
				}else{
					for(int jj =0;mp2[j].size();jj++){
						char mychar = mp2[j][jj];
						vector<bool> myalive(n,false);
						for(auto it = mp[mychar].begin();it!=mp[mychar].end();it++){
							myalive[*it]=true;
						}
						bool canitake = true;
						for(int kk = 0;kk<n;kk++){
							if(!myalive[kk] &&!alive[kk]) canitake =false;
						}
					}
					if(ch=='#'){
						cout<<-1<<endl;
						return;
					}
				}
			}
		}
		vector<bool> myalive(n,false);
						for(auto it = mp[ch].begin();it!=mp[ch].end();it++){
							myalive[*it]=true;
						}
						bool canitake = true;
						for(int kk = 0;kk<n;kk++){
							if(!myalive[kk] &&!alive[kk]) {
								canitake =false;
								cout<<-1<<endl;
								return;
							}
						}
		ans+=ch;
	}
	cout<<ans<<endl;
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
