#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
void buildTree(ll* arr,ll* tree,ll start,ll end,ll node){//O(len of arr)
    if(start==end){
        tree[node]=arr[start];//same as arr[end];
        return;
    }
    ll mid=start + (end-start)/2;
    buildTree(arr,tree,start,mid,2*node);
    buildTree(arr,tree,mid+1,end,2*node+1);
    tree[node]=tree[2*node]+tree[2*node+1];
}
void updateTree(ll* arr,ll* tree,ll start,ll end,ll node,ll idx,ll val){
    if(start==end){
        tree[node]=arr[idx]=val;
        return;
    }
    ll mid=start+(end-start)/2;
    if(idx<=mid){
        updateTree(arr,tree,start,mid,node*2,idx,val);
    }else{
        updateTree(arr,tree,mid+1,end,node*2+1,idx,val);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(ll* tree,ll start,ll end,ll node,ll left,ll right){
    //completely outside
    if(start>right || end<left){
        return 0;
    }
    //completely inside
    if(start>=left && end<=right){
        return tree[node];
    }
    //partially inside i.e. partially outside
    ll mid = start+(end-start)/2;
    ll ans1 = query(tree,start,mid,node*2,left,right);
    ll ans2 = query(tree,mid+1,end,node*2+1,left,right);
    return ans1+ans2;
}
int main(){
    ll arr[]={1,2,3,4,5};
    ll n=5;
    ll* tree=new ll[4*n];

    buildTree(arr,tree,0,n-1,1);

    for(ll i=1;i<4*n;i++) cout<<tree[i]<<endl;

    updateTree(arr,tree,0,n-1,1,2,10);
    cout<<"3rd value replaced with 10"<<endl;

    for(ll i=1;i<4*n;i++) cout<<tree[i]<<endl;

    ll ans=query(tree,0,n-1,1,1,3);
    cout<<"Sum b/w 2nd index to 4th index "<<ans<<endl;
    return 0;
}