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

void solve(ll caseno){
	ll i,j,n;
    string s;
    cin>>s;
    n=s.size();
    fo(i,0,n-1){
        if(s[i]==s[i+1]&&s[i]!='?'&&s[i+1]!='?') {
            cout<<-1<<endl;
            return;
        }
    }
    ll from=0,len=0;
    char r,l='a';
    fo(i,0,n){
        if(s[i]!='?'){
            if(l=='a'&&s[i]=='b') r='c';
            else if(l=='a'&&s[i]=='c') r='b';
            else if(l=='b'&&s[i]=='c') r='a';
            else if(l=='b'&&s[i]=='a') r='c';
            else if(l=='c'&&s[i]=='a') r='b';
            else if(l=='c'&&s[i]=='b') r='a';
            else if(l=='a'&&s[i]=='a'){
                l='b';r='c';
            }
            else if(l=='b'&&s[i]=='b'){
                l='a';r='c';
            }
            else if(l=='c'&&s[i]=='c'){
                l='b';r='a';
            }
            fo(j,from,from+len){
                if((j-from)%2==0){
                    s[j]=r;
                }else{
                    s[j]=l;
                }
            }
            len=0;
            from=i+1;
            l=s[i];
        }else{
            len++;
        }
    }
    if(l=='b') r='a';
    if(l=='c') r='a';
    if(l=='a'){
        r='b';
    }
    fo(j,from,from+len){
    if((j-from)%2==0){
            s[j]=r;
        }else{
            s[j]=l;
        }
    }
    cout<<s<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
