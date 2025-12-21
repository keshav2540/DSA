#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>&mat){
    int k;
    int n=mat.size(),m=mat[0].size();
    int arr[n][m];
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       arr[j][n-1-i]=mat[i][j];
    }
    }
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       cout<<arr[i][j]<<" ";
       }cout<<endl;  }
    }

    void optimal(vector<vector<int>>&mat){
           int n=mat.size(),m=mat[0].size();
            int arr[n][m];
    for(int i=0;i<n;i++){
    for(int j=i;j<m;j++){
       swap(mat[i][j],mat[j][i]);
    }}
    for(int i=0;i<m;i++) reverse(mat[i].begin(),mat[i].end());
     for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       cout<<mat[i][j]<<" ";
       }cout<<endl;  }
}

    
int main() {
    vector<vector<int>>mat={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  int n=mat.size(),m=mat[0].size();
 optimal(mat);
return 0;}