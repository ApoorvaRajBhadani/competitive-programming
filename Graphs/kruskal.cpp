#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int v1,v2,w;
};
bool lesserweight(Edge a,Edge b){
    return (a.w<b.w);
}
int main()
{
    int n, e,i;
    cin >> n >> e;
    Edge edges[e];
    for(i=0;i<e;i++){
        cin>>edges[i].v1>>edges[i].v2>>edges[i].w;
    }
    sort(edges,edges+e,lesserweight);
    int count = 0,parent[n];
    for(i=0;i<n;i++) 
        parent[i] = i;
    i=0;
    Edge mst[n-1];
    while(count<n-1){
        //both vertices have diff parent
        if(parent[edges[i].v1]!= parent[edges[i].v2]){
            mst[count].v1 = min(edges[i].v1,edges[i].v2);
            mst[count].v2 = max(edges[i].v1,edges[i].v2);
            mst[count].w = edges[i].w;
            int newtopparent = parent[edges[i].v2];
            for(int j = 0;j<n;j++){
                if(parent[j] == edges[i].v1){
                    parent[j] = newtopparent;
                }
            }
            count++;
        }
        i++;
    }
    for(i=0;i<n-1;i++){
        cout<<mst[i].v1<<" "<<mst[i].v2<<" "<<mst[i].w<<endl;
    }
  return 0;
}

