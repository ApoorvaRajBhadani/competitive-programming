#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define fo(i,k,n) for(int i=k;i<=n;++i)
#define endl '\n'
bool isPal(string str) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = str.length() - 1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            //printf("%s is Not Palindrome", str); 
            return false; 
        } 
    } 
    return true;
    //printf("%s is palindrome", str); 
} 
string longestPalSubstr(string str) 
{ 
	ll len = str.length();
	for(ll i =len;i>=1;i--){
		string bgn = str.substr(0,i);
		if(isPal(bgn)) return bgn;
		string endd = str.substr(len-i,i);
		if(isPal(endd)) return endd;
	}
	string ans ="";
	return ans;
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	string input[t];
	for(ll i=0;i<t;i++) cin>>input[i];
	for(ll iii=0;iii<t;iii++){
		string s,a="",b="";
		s=input[iii];
		ll len = s.length();
		ll i=0,j=len-1;
		while(s[i]==s[j] && i<j){
			a = a+s[i];
			b = s[j]+b;
			i++;
			j--;
		}
		//cout<<i<<" "<<j<<endl;
		string fff = s.substr(i,j-i+1);
		cout<<a;
		string ans=longestPalSubstr(fff);
		cout<<ans;
		cout<<b<<endl;
	}
	return 0;
}
