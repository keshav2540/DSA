#include <bits/stdc++.h>
using namespace std;
int maxsum(vector<int>&arr){
    stack<int>st;
    int maxA=0;
    int n=arr.size();
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n||arr[st.top()]>=arr[i]))
       { int height=arr[st.top()];st.pop();
        int width=0;
        if(st.empty()){
            width=i;
        }
        else width=i-st.top()-1;
        maxA=max(maxA,width*height);}
      st.push(i);
    }return maxA;
}
int sol(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    int ans=0;
    vector<int>height(m,0);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(mat[i][j] == 1) height[j]++;
          else height[j] = 0;
        } ans=max(ans,maxsum(height));
    } return ans;
}
int main() {
vector<vector<int>>mat{{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
cout<<sol(mat);
    return 0;
}