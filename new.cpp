#include <iostream>

using namespace std;

int main()
{
    int n,m,i,v,q;
    cin>>n>>m;
    string s[n],t[m],word;
    for(i=1;i<n;i++){
        cin>>s[i];
    }
    cin>>s[0];
    for(i=1;i<m;i++){
        cin>>t[i];
    }
    cin>>t[0];
    cin>>q;
    while(q--){
        cin>>v;
        word="";
        word+=s[v%n];
        word+=t[v%m];
        cout<<word<<endl;
    }
    return 0;
}

