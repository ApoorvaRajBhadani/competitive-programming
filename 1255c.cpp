#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll tarr[100005][3];
vi tid[100005];
void solve(ll caseno){
	ll i,j,n;
    cin>>n;
    fo(i,0,n-2){
        cin>>tarr[i][0]>>tarr[i][1]>>tarr[i][2];
        tid[tarr[i][0]].pbb(i);
        tid[tarr[i][1]].pbb(i);
        tid[tarr[i][2]].pbb(i);
    }
    ll number,id,pid,last=-1;
    vi ans;
    set<ll> idscame;
    fo(i,1,n+1){
        if(tid[i].size()==1){
            number=i;
            if(last==-1) last=i;
            id=tid[i][0];
            idscame.insert(id);
            
        }
    }
    ans.pbb(number);
    ll n1,n2;
        if(tarr[id][0]==number){
            n1=tarr[id][1];
            n2=tarr[id][2];
        }else if(tarr[id][1]==number){
            n1=tarr[id][0];
            n2=tarr[id][2];
        }else{
            n1=tarr[id][0];
            n2=tarr[id][1];
        }
    pid=id;
    if(tid[n1].size()==2){
        number=n1;
        if(tid[n1][0]!=pid) id=tid[n1][0];
        else id=tid[n1][1];
    }else{
        number=n2;
        if(tid[n2][0]!=pid) id=tid[n2][0];
        else id=tid[n2][1];
    }
    while(ans.size()<n-1){
        //cout<<number<<' '<<id<<endl;
        ans.pbb(number);
        ll n1,n2;
        if(tarr[id][0]==number){
            n1=tarr[id][1];
            n2=tarr[id][2];
        }else if(tarr[id][1]==number){
            n1=tarr[id][0];
            n2=tarr[id][2];
        }else{
            n1=tarr[id][0];
            n2=tarr[id][1];
        }
        ll nxtid,nxtnum;
        for(auto id1:tid[n1]){
            for(auto id2:tid[n2]){
                if(id1==id2 && id1!=id) {
                    nxtid = id1;
                   // cout<<"nxtid"<<id1<<endl;
                    idscame.insert(nxtid);
                }
            }
        }
        for(auto ids:tid[n1]){
            if(ids==pid) nxtnum=n1;
        }
        for(auto ids:tid[n2]){
            if(ids==pid) nxtnum=n2;
        }
        number=nxtnum;
        pid=id;
        id=nxtid;
    }
    ans.pbb(last);
    for(auto num:ans) cout<<num<<' ';
    cout<<endl;
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
