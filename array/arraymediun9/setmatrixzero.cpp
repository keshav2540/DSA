#include <bits/stdc++.h>
using namespace std;
void bf(vector<vector<int>>&matrix){ // use a other temp matrix
    vector<vector<int>>mat=matrix;
    
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(matrix[i][j]==0){
    for(int k=0;k<n;k++){
        mat[k][j]=0;
    }
    for(int l=0;l<m;l++){
       mat[i][l]=0;
    }}}}
 matrix=mat;}
 void bfs(vector<vector<int>>&matrix){ // use a other method matrix
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(matrix[i][j]==0){
    for(int k=0;k<n;k++) if(matrix[k][j]!=0) matrix[k][j]=-1;
    for(int l=0;l<m;l++)if(matrix[i][l]!=0) matrix[i][l]=-1;}}}

 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(matrix[i][j]==-1) matrix[i][j]=0;}}}

void better(vector<vector<int>>&matrix){
    
    int n=matrix.size(),m=matrix[0].size();
    int col[m],row[n];
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(matrix[i][j]==0){
        col[j]=1;
        row[i]=1;
}}}      
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(col[j]==1|| row[i]==1){
        matrix[i][j]=0;
}}}      
}
void optimal(vector<vector<int>>&matrix){
    int col0=1;
    
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(matrix[i][j]==0){
        matrix[i][0]=0; 
        
        if(j!=0) matrix[0][j]=0;
         else col0=0;
}}}      
    for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        if(matrix[i][j]!=0)
    { if(matrix[i][0]==0|| matrix[0][j]==0){
        matrix[i][j]=0;}
}}} 
if(matrix[0][0]==0)for(int j=0;j<m;j++) matrix[0][j]=0;
    if(col0==0)for(int j=0;j<n;j++) matrix[j][0]=0;
   
}
int main() {
    vector<vector<int>>matrix={{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
    optimal(matrix);
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<matrix[i][j]<<" ";
    }
cout<<endl;}
    return 0;
}