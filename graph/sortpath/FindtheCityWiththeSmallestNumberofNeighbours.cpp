#include <bits/stdc++.h>
using namespace std;
// this is breute force way
int numberofNeighbours_findcity(int n,vector<vector<int>>&grid,int threshold){
 vector<vector<int>>dis(n,vector<int>(n,1e9));
 for(auto it :grid){
    dis[it[0]][it[1]]=it[2];
    dis[it[1]][it[0]]=it[2];
 }
 for(int i=0;i<n;i++) dis[i][i]=0;
 for(int k=0;k<n;k++){
     for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(dis[i][k]=INT32_MAX||dis[k][j]==INT32_MAX)continue;
          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
 }
 }
}
int countcity=n;
int cityno=-1;
for(int city=0;city<n;city++){
    int count=0;
    for(int adjcity=0;adjcity<n;adjcity++){
        if(dis[city][adjcity]<=threshold) count++;
    }
    if(count<=countcity){
        countcity=count;
        cityno=city;
    }
}
 return cityno;
}

int main() {
    vector<vector<int>>grid={{0,1,3},{1,2,1},{3,2,1},{3,1,4}};
    cout<<numberofNeighbours_findcity(4,grid,4);
    return 0;
}