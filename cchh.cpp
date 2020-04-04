#include<bits/stdc++.h>
using namespace std;
 
long long n,m,t,q,x,y,mod = 1e9 + 7;
bool vis[2000][2000];
vector< vector<int>> mat;
int comp;
vector<int>factorial(1e6+1);
void pre_calculate(){       // calculating factorial
 
    factorial[0] = 1;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}
 
bool check(int i,int j){
    if(i<1||i>n)return false;
    if(j<1||j>m)return false;
    return true;
 
}
 
void explore(int i,int j){
    //cout<<"I is "<<i<<" J is "<<j<<endl;;
    vis[i][j]=true;
    comp++;
    int xaxis[]={-2,-2,-1,-1,1,1,2,2};
    int yaxis[]={-1,1,-2,2,-2,2,-1,1};
 
    for(int z=0;z<8;z++){
         //   cout<<"ZZZ caused axis "<< i+xaxis[z]<<" and "<<j+yaxis[z]<<endl;
        if(check(i+xaxis[z],j+yaxis[z])){
            if(mat[i+xaxis[z]][j+yaxis[z]]==1&&
               !vis[i+xaxis[z]][j+yaxis[z]]){
                   explore(i+xaxis[z],j+yaxis[z]);
            }
        }
    }
    //cout<<"comp is"<<comp<<endl;;
}
 
 
int main(){
     ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    pre_calculate();
    
    cin>>t;
    while(t--){
    long long ans=1;
    cin>>n>>m>>q;
    mat.clear();
 
    for(int i=0;i<=n;i++){
        vector<int>a(m+1,0);
        mat.push_back(a);
    }
 
 
 
    for(int i=0;i<q;i++){
        cin>>x>>y;
        mat[x][y]=1;
    }
 
 
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                vis[i][j]=false;}
 
    }
 
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]&&mat[i][j]==1){
                comp=0;
                explore(i,j);
                cout<<"comp is "<<comp<<endl;
                ans=(ans*factorial[comp])%mod;
            }
        }
    }
    cout<<ans<<endl;
 
    }
 
}
