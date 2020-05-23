#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007//998244353
#define p_b push_back
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
void solve(){
	ll i,j,n,m;
	cin>>n>>m;
	vector<string> vec(n);
	vector<bool> visit(n,false);
	string ansf="",ansm="",anse="";
	fo(i,0,n-1) cin>>vec[i];
	
	fo(i,0,n-1){
		if(visit[i]) continue;
		string t = vec[i];
		reverse(all(t));
		ll revat=-1;
		fo(j,0,n-1){
			string tt = vec[j];
			if(tt==t && !visit[j]){
				if(j!=i) {
					revat=j;
					break;
				}
			}
		}
		if(revat>=0){
				visit[i]=visit[revat]=true;
				ansf+=vec[i];
				anse=vec[revat]+anse;
		}
	}
	fo(i,0,n-1){
		string t = vec[i];
		reverse(all(t));
		if(t==vec[i] && !visit[i]){
			if(vec[i].size()>ansm.size()) ansm = t;
		}
	}
	cout<<ansf.size()*2+ansm.size()<<endl;
	cout<<ansf+ansm+anse<<endl;
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
