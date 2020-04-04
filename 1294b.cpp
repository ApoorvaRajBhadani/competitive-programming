#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll; 
int main(){
	ll t,x,y,n,i,prev,r,u,j;
	cin>>t;
	while(t--){
		cin>>n;
		 vector< pair <int,int> > vect;
		for(i=1;i<=n;i++){
			cin>>x>>y;
			vect.push_back(make_pair(x,y));
		}
		sort(vect.begin(), vect.end()); 
		//check if possible
		prev = vect[0].second;
		for(i=1;i<n;i++){
			if(vect[i].second<prev) break;
			prev = vect[i].second;
		}
		if(i==n){
			cout<<"YES\n";
			string s="";
			r=0;u=0;
			for(i=0;i<n;i++){
				if(vect[i].first>r){
					j=vect[i].first-r;
					while(j--){
						s+="R";
					}
				}
				if(vect[i].second>u){
					j=vect[i].second-u;
					while(j--){
						s+="U";
					}
				}
			}
			cout<<s<<endl;
		}
		else cout<<"NO\n";
	}
	return 0;
}
