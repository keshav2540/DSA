#include <bits/stdc++.h>
using namespace std;
void solvemaze(int i,int j,int n,vector<vector<int>>&maze,vector<string>&ans,vector<vector<int>>&visit,string move,int di[],int dj[]){
       if(i==n-1 &&j==n-1){
        ans.push_back(move);
       }   
       string dir="DRLU";
       for(int ind=0;ind<4;ind++){
        int nextj=j+dj[ind];
        int nexti=i+di[ind];
        if(nexti>=0 && nextj>=0&& nexti<n &&nextj<n&& !visit[nexti][nextj] && maze[nexti][nextj]==1){
            visit[i][j]=1;
            solvemaze(nexti,nextj,n,maze,ans,visit,move+dir[ind],di,dj);
             visit[i][j]=0;
        }
       }
}

int main() {
 vector<vector<int>>maze={
    {1,0,0,0},
    {1,1,0,1},
    {1,1,0,0},
    {0,1,1,1},
 };
 int n=maze.size();
 vector<string>ans;
 string move="";
 int di[]={1,0,0,-1};
 int dj[]={0,1,-1,0};
 vector<vector<int>>visit(n,vector<int>(n,0));
 solvemaze(0,0,n,maze,ans,visit,move,di,dj);
 for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    } cout<<endl;
   }
    return 0;
}