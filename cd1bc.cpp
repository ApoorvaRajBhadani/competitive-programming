#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
int T=1;
int a[32];

void fun()
{
	int i;
	a[0]=1;
	for(i=1;i<32;i++)
		a[i]=a[i-1]*2;
}

int power(int a,int b,int m=mod)
{
	if(b==0)	return 1;
	if(b==1)	return a;
	int res=power(a,b/2,m);
	res=(res*res)%m;
	if(b&1)	res=(res*a)%m;
	return res;
}

int modinv(int a){ return power(a,mod-2);}

void solve()
{
	cout<<"Case #"<<T++<<": ";
	int x,y,i;
	cin>>x>>y;
	int val=abs(x)+abs(y);
	if(val%2==0)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	int val1=val;
	int cnt=0;
	while(val1)
	{
		cnt++;
		val1/=2;
	}
	string s;
	int b[32],c[32];
	for(i=0;i<cnt;i++)
	{
		b[i]=0;
		if(a[i]&val)
			b[i]=1;
	}
	/*for(i=0;i<cnt;i++)
		cout<<b[i]<<" ";
	cout<<endl;*/
	for(i=0;i<cnt-1;i++)
	{
		c[i]=1;
		if(b[i+1]==0)
			c[i]=-1;
		//cout<<i<<" "<<c[i]<<endl;
	}
	c[cnt-1]=1;
	/*for(i=0;i<cnt;i++)
		cout<<c[i]<<" ";
	cout<<endl;*/
	
	
	int p=abs(x);
	for(i=0;i<cnt;i++)
	{
		s+='N';
		if(p&a[i])
		{
			//cout<<"i is  "<<i<<endl;
			if(c[i]==-1)
			{
				s[i]='W';
				p+=a[i];
			}
			else
				s[i]='E';
		}
	}
	for(i=0;i<cnt;i++)
	{
		if(s[i]!='W' && s[i]!='E')
			if(c[i]==-1)
				s[i]='S';
	}
	//reverse(s.begin(),s.end());
	//cout<<s<<endl;
	if(x<0)
	{
		for(i=0;i<cnt;i++)
		{
			if(s[i]=='W')
				s[i]='E';
			else if(s[i]=='E')
				s[i]='W';
		}
	}
	if(y<0)
	{
		for(i=0;i<cnt;i++)
		{
			if(s[i]=='S')
				s[i]='N';
			else if(s[i]=='N')
				s[i]='S';
		}
	}
	cout<<s<<endl;
	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;cin>>t;
	fun();
	while(t--)	solve();
	return 0;
}
