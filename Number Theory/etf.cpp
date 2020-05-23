typedef long long int ll;
ll etf[1000001];
void func(long long n)
{
	//sieve
    ll i,j;
    for(i=0;i<=1000000;i++) etf[i]=i;
    for(i=2;i<=1000000;i++){
        if(etf[i]==i){
            for(j=i;j<=1000000;j+=i){
                etf[j]/=i;
                etf[j]*=(i-1);
            }
        }
    }
    ll sum=1;
    for(i=1;i<=n;i++){
        if(n%i==0){
            sum+=i*etf[i];
        }
    }
    sum*=n;
    sum/=2;
    cout<<sum<<endl;
}
