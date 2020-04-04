/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,i,len,j,prev,curr,mn,mx,c=0,mpl=0,mnp=0,mxp=0,ss=0;
    cin>>n;
    int arr[n][3];
    for(i=1;i<=n;i++){
        cin>>len;
        arr[i-1][0]=0;
        cin>>prev;
        mn=mx=prev;
        for(j=2;j<=len;j++){
            cin>>curr;
            mn=min(mn,curr);
            mx=max(mx,curr);
            if(prev<curr) arr[i-1][0]=1;
            prev=curr;
        }
        arr[i-1][1]=mn;
        arr[i-1][2]=mx;
    }
    map<long long int,long long int> mp;
    for(i=0;i<n;i++){
        if(arr[i][0]==1){ c+=(n+n); ss++;}
        else{
            // for(j=0;j<n;j++){
            //     if(arr[j][0]==1) c++;
            //     else if(arr[i][1]<arr[j][2]) c++;
            // }
            mpl++;
            mp[arr[i][1]]+=1;
            mp[arr[i][2]]+=10;
        }
    }
    c-=((1+(ss-1))*(ss-1));
c-=ss;
    //mpl=mp.size();
    for(auto it=mp.begin();it!=mp.end();it++){
        
        if(it->second/10==1) mxp++;
        if(it->second%10==1){ 
            mnp++;
            c+=(mpl-mxp);
        }
    }
    cout<<c;
    return 0;
}

