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
	ll i,j,n;
	cin>>n;
	ll arr[n][n];
	for(i=0;i<n;i++){
		string s;
		cin>>s;
		for(j=0;j<n;j++){
			arr[i][j]=s[j]-'0';
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i][j]){
				//cout<<arr[i][j]<<endl;
				bool isposs = false;
				if(i==n-1)isposs=true;
				else if(arr[i+1][j]) isposs=true;
				if(j==n-1) isposs=true;
				else if(arr[i][j+1]) isposs=true;
				if(!isposs){
					cout<<"NO"<<endl;
					return;
				}
			}
		}
	}
	cout<<"YES"<<endl;
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
char ch;ll nums=0;
		for(int ii = 0;ii<=25;i++){
			vector<bool> tobedead(false,n);
			for(auto ids:v[ii]) tobedead[ids]=true;
			bool canitake =true;
			for(int jj = 0;jj<n;jj++) if(!alive[jj] && !tobedead[jj])canitake = false;
			if(canitake&&v[ii].size()>=nums){
				ch = char('a'+ii);
				nums = v[ii].size();
			} 
		}
		vector<bool> tobedead(false,n);
		for(auto ids:v[ch-'a']) tobedead[ids]=true;
		for(int jj = 0;jj<n;jj++) if(!tobedead[jj]){
			if(alive[jj])alive[jj]=false;
			else{cout<<-1<<endl;return;}
		}
