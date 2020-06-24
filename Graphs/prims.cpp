#include <bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int va,vb,w;
};

int main()
{
    int n,e,i,j;
    cin>>n>>e;
    int** edges = new int*[n];
    for(i=0;i<n;i++){
        edges[i] = new int[n];
        for(j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[s][d] = edges[d][s] = w;
    }
    int count =0;
    bool visited[n], unvisited[n];
    for(i=0;i<n;i++) {
        unvisited[i] = true;
        visited[i] = false;
    }
    int parent[n],weight[n];
    parent[0]=-1;
    for(i=1;i<n;i++){
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    while(count<n){
        int currvetx=-1,minw = INT_MAX;
        for( i = 0;i<n;i++){
            if(weight[i]<minw && unvisited[i]){
                minw = weight[i];
                currvetx = i;
            }
        }
        count++;
        for(i=0;i<n;i++){
            if(edges[i][currvetx]>0&&edges[i][currvetx]<weight[i]&&unvisited[i]){
                parent[i] = currvetx;
                weight[i] = edges[i][currvetx];
            }
        }
        unvisited[currvetx]=false;
    }
    for(i=1;i<n;i++){
        cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<weight[i]<<endl;
    }
  return 0;
}

