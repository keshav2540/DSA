#include <bits/stdc++.h>
using namespace std;
 class solution{
    void dfs(int sr,int sc,vector<vector<int>>&ans,vector<vector<int>>&image,int newcolor,vector<int>&delrow,vector<int>&delcol,int intialcolur){
         ans[sr][sc]=newcolor;
         int n=image.size();
         int m=image[0].size();

         for(int i=0;i<4;i++){
          int nrow=sr+delrow[i];
          int ncol=sc+delcol[i];
          if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==intialcolur&&ans[nrow][ncol]!=newcolor){
            dfs(nrow,ncol,ans,image,newcolor,delrow,delcol,intialcolur);
          }
         }
    }
    public:
     vector<vector<int>>follodfill(vector<vector<int>>&image,int sr,int sc,int newcolur){
       int intialcolor=image[sr][sc];
       vector<vector<int>>ans=image;
       vector<int>delrow={-1,0,1,0};
       vector<int>delcol={0,1,0,-1};
       dfs(sr,sc,ans,image,newcolur,delrow,delcol,intialcolor);
       return ans;
     }
 };
int main() {
    vector<vector<int>>image={{0,1,1},{1,1,0},{1,0,1}};
    int newcolor=3;
    solution s;
    for(auto i:s.follodfill(image,0,0,newcolor)){
        for(int j:i){
            cout<<j<<" ";
        }cout<<endl;
    }

    return 0;
}