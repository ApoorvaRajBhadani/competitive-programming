#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(i=k;i<=n;i++)
#define endl '\n'
char mainmat[30][30];
ll alphamat[26][30][30];
ll alphacount[26];
bool priority[26][26];
bool ishole(ll alpha){
	ll i,j,count=0;
	fo(j,0,29){
		char prev='#';
		for(i=29;i>=0;i--){
			if(alphamat[alpha][i][j]==1){
				if(prev!='#'){
					//alpha k pehle prev aana chahiye
					priority[alpha][prev-'A']=true;
					priority[prev-'A'][alpha]=false;
				}
				break;
			}else if(alphamat[alpha][i][j]==0){
				alphamat[alpha][i][j]=2;
				count++;
			}else if(alphamat[alpha][i][j]==2){
			}
			prev = mainmat[i][j];
		}
	}
	//if(alpha==('O'-'A')){
		//fo(i,0,29){
			//fo(j,0,29){
				//cout<<alphamat[alpha][i][j];
			//}
			//cout<<endl;
		//}
	//}cout<<endl;
	for(i=0;i<=29;i++){
		for(j=29;j>=0;j--){
			if(alphamat[alpha][i][j]==1){
				break;
			}else if(alphamat[alpha][i][j]==0){
				alphamat[alpha][i][j]=2;
				count++;
			}else if(alphamat[alpha][i][j]==2){
			}
		}
	}
	//if(alpha==('O'-'A')){
		//fo(i,0,29){
			//fo(j,0,29){
				//cout<<alphamat[alpha][i][j];
			//}
			//cout<<endl;
		//}
	//}cout<<endl;
	for(j=0;j<=29;j++){
		for(i=0;i<=29;i++){
			if(alphamat[alpha][i][j]==1){
				break;
			}else if(alphamat[alpha][i][j]==0){
				alphamat[alpha][i][j]=2;
				count++;
			}else if(alphamat[alpha][i][j]==2){
			}
		}
	}
	//if(alpha==('O'-'A')){
		//fo(i,0,29){
			//fo(j,0,29){
				//cout<<alphamat[alpha][i][j];
			//}
			//cout<<endl;
		//}
	//}cout<<endl;
	for(i=0;i<=29;i++){
		for(j=0;j<=29;j++){
			if(alphamat[alpha][i][j]==1){
				break;
			}else if(alphamat[alpha][i][j]==0){
				alphamat[alpha][i][j]=2;
				count++;
			}else if(alphamat[alpha][i][j]==2){
			}
		}
	}
	//if(alpha==('O'-'A')){
		//fo(i,0,29){
			//fo(j,0,29){
				//cout<<alphamat[alpha][i][j];
			//}
			//cout<<endl;
		//}
	//}cout<<endl;
	//cout<<(char)(alpha+'A')<<endl;
	//cout<<count<<' '<<alphacount[alpha]<<endl;
	if(count+alphacount[alpha]==900){
		return false;
	}return true;
}
bool comp(char x,char y){
	return !(priority[x-'A'][y-'A']);
}
void solve(){
	ll i,j,r,c;
	cin>>r>>c;
	memset(priority,0,sizeof(priority));
	memset(mainmat,'#',sizeof(mainmat));
	memset(alphamat,0,sizeof(alphamat));
	memset(alphacount,0,sizeof(alphacount));
	map<char,bool> mp;
	fo(i,0,r-1){
		fo(j,0,c-1){
			cin>>mainmat[i][j];
			mp[mainmat[i][j]]=true;
			alphamat[mainmat[i][j]-'A'][i][j]=1;
			alphacount[mainmat[i][j]-'A']++;
		}
	}
	fo(i,0,25){
		bool bbb = ishole(i);
		if(bbb){
			cout<<-1<<endl;
			return;
		}
	}
	vector<char> vec;
	for(char cc='A';cc<='Z';cc++){
		if(mp[cc]) vec.push_back(cc);
	}
	sort(vec.begin(),vec.end(),comp);
	for(auto it=vec.begin();it!=vec.end();it++) cout<<*it;
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	//t=1;
	for(ll i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
