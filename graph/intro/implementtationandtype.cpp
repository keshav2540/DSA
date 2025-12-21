/*type of graph
directed and undirected(depend on edage) node and vertex,cycle(st and endind node is same),
path(term)
1degre of graph=number of edges
total degree of graph=2*eddes;
 indegree(incoming)
 outdegere(outgoing)
 edge wet
 greaph representation
 adjacay matrix a[i][j]=1/edge wet;
 adj[n+1][n+1]size
 adjecylist
 vec<int>arr[];
 with edgeweight vec<pair<int,edgeweight>>arr[];
 comuted complement sparetedparts 
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int garph[6][6]={{0}};
//     for(int i=0;i<6;i++){
//         int u,v;
//         cin>>u>>v;
//         garph[u][v]=1;
//         garph[v][u]=1;
//     }
//     for(int i=0;i<6;i++){
//         for(int j=0;j<6;j++){
//             cout<<garph[i][j]<<" ";
//         }cout<<endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
//  vector<pair<int,int>>adj[7]; WITH EDGE WEIGHT 
 vector<int>adj[7];
 adj[0]={};
 adj[1]={2,3};
 adj[2]={1,4,5};
 adj[3]={1,4};
 adj[4]={2,5,3};
 adj[5]={2,4};
    return 0;
}