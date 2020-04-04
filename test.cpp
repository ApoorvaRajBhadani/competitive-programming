#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
void buildtree(int* arr,int* tree,int start,int end,int treenode){
	if(start==end){
		tree[treenode] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildtree(arr,tree,start,mid,treenode*2);
	buildtree(arr,tree,mid+1,end,2*treenode+1);
	tree[treenode] = min(tree[2*treenode],tree[2*treenode+1]);
}
void updateSegmentTreeLazy(int* tree,int* lazy,int low,int high,int startR,
int endR,int currPos,int inc){
	if(low>high) 
		return;
		
	//if lazy tree contains some updation first use that
	if(lazy[currPos]!=0){
		tree[currPos]+=lazy[currPos];
		//if the node is not leaf node update its child for future lazy increments
		if(low!=high){
			lazy[2*currPos]+=lazy[currPos];
			lazy[2*currPos+1]+=lazy[currPos];
		}
		lazy[currPos]=0;
	}
	//updation-no overlap
	if(startR>high||endR<low){
		return;
	}
	//updation-complete overlap
	if(startR<=low&&high<=endR){
		tree[currPos]+=inc;
		if(low!=high){
			lazy[2*currPos]+=inc;
			lazy[2*currPos+1]+=inc;
		}
		return;
	}
	//updation-partial overlap
	int mid = (low+high)/2;
	updateSegmentTreeLazy(tree,lazy,low,mid,startR,endR,2*currPos,inc);
	updateSegmentTreeLazy(tree,lazy,mid+1,high,startR,endR,2*currPos+1,inc);
	tree[currPos] = min(tree[2*currPos],tree[2*currPos+1]);
}
int main(){
	int arr[]={1,3,-2,4};
	int* tree=new int[4*4]();
	buildtree(arr,tree,0,3,1);
	int* lazy = new int[16]();
	//print
	updateSegmentTreeLazy(tree,lazy,0,3,0,3,1,5);
	updateSegmentTreeLazy(tree,lazy,0,3,0,1,1,2);
	
	for(int i=1;i<2*4;i++) 
		cout<<tree[i]<<endl;
	cout<<endl;
	for(int i=1;i<2*4;i++) 
		cout<<lazy[i]<<endl;
	return 0;
}
