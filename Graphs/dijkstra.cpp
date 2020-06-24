#include <bits/stdc++.h>
using namespace std;


int main()
{
  int i,j,n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(i=0;i<n;i++){
        edges[i] = new int[n];
        for(j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        edges[v1][v2] = edges[v2][v1] = w;
    }
    bool* visited = new bool[n];
    for(i=0;i<n;i++) visited[i] = false;
    int* dist = new int[n];
    dist[0] = 0;
    for(i=1;i<n;i++) dist[i] = INT_MAX;
    
    //dijkstra's algo
    for(i=0;i<n-1;i++){
        //select node to explore
        int curnode=-1,wgt=INT_MAX;
        for(j=0;j<n;j++){
            if(!visited[j]&&dist[j]<wgt){
                wgt = dist[j];
                curnode = j;
            }
        }
        //explore this node
        visited[curnode] = true;
        for(j=0;j<n;j++){
            if(!visited[j]&&edges[curnode][j]>0&&(dist[j] > dist[curnode]+edges[curnode][j])){
                dist[j] = dist[curnode]+edges[curnode][j];
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
  return 0;
}

