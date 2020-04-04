#include<iostream> 
#include<climits> 
using namespace std;
typedef long long int ll; 
int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		ll c=0;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			c+=a[i];
		}
		int kad = max(maxSubArraySum(a,n-1),maxSubArraySum(a+1,n-1));
		if(c>kad) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
