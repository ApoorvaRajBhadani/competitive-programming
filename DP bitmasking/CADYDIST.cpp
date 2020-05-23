typedef long long ll;
long long solve(int like[][MAXN],int n)
{
    ll* dp = new ll[1<<n];
    for(ll i=0;i<(1<<n);i++) dp[i]=0;
    dp[0]=1;
    ll mask,j,temp,k;
    for(mask=1;mask<(1<<n);mask++){
        temp=mask;
        k=0;
        while(temp>0){
            if(temp&1 == 1) k++;
            temp/=2;
        }
        k--;
        for(j=0;j<n;j++){
            if(mask&(1<<j)  &&  like[k][j]){
                dp[mask]+=dp[mask^(1<<j)];
                //cout<<dp[mask]<<endl;
            }
        }
    }
    return dp[(1<<n)-1];
}
