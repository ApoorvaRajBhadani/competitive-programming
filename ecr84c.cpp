#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
struct Chip{
	ll sx,sy,fx,fy,d;
};
bool compare(Chip a,Chip b){
	return a.d<b.d;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,m,k,i,j,netup=0,netrt=0;
	string seq="";
	cin>>n>>m>>k;
	vector<Chip> chips;
	for(i=0;i<k;i++){
		Chip newchip = {0,0,0,0,0};
		cin>>newchip.sx>>newchip.sy;
		chips.push_back(newchip);
	}
	for(i=0;i<k;i++){
		ll x,y;
		cin>>x>>y;
		chips[i].fx=x;
		chips[i].fy=y;
	}
	for(i=0;i<k;i++){
		ll d;
		d = abs(chips[i].fx - chips[i].sx);
		d+= abs(chips[i].fy - chips[i].sy);
		chips[i].d=d;
	}
	sort(chips.begin(),chips.end(),compare);
	for(i=0;i<k;i++){
		Chip ch = chips[i];
		//ch.sx-=netup;
		//if(ch.sx<1) ch.sx=1;
		//else if(ch.sx>n) ch.sx=n;
		//ch.sy+=netrt;
		//if(ch.sy>m) ch.sy = m;
		//else if(ch.sy<1) ch.sy = 1;
		//cout<<"hi"<<ch.sx<<' '<<ch.sy<<endl;
		ll timesup = ch.sx-ch.fx ;
		if(timesup>0){
			while(timesup){
				seq+='U';
				netup++;
				timesup--;
			}
		}else if(timesup<0){
			while(timesup){
				seq+='D';
				netup--;
				timesup++;
			}
		}
		ll timesrt = ch.fy-ch.sy;
		if(timesrt>0){
			while(timesrt){
				seq+='R';
				netrt++;
				timesrt--;
			}
			
		}else if(timesrt<0){
			while(timesrt){
				seq+='L';
				netrt--;
				timesrt++;
			}
		}
		//seq+='.';
		//update all
		for(j=i+1;j<k;j++){
			Chip ch = chips[j];
		ch.sx-=netup;
		if(ch.sx<1) ch.sx=1;
		else if(ch.sx>n) ch.sx=n;
		ch.sy+=netrt;
		if(ch.sy>m) ch.sy = m;
		else if(ch.sy<1) ch.sy = 1;
		chips[j]=ch;
		}
		netrt=netup=0;
	}
	if(seq.size()<=(2*n*m)){
		cout<<seq.size()<<endl;
		cout<<seq;
	}else{
		cout<<-1;
	}
	return 0;
}






















