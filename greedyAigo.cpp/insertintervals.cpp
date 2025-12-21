#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>insertintervals(vector<vector<int>>matrix,vector<int>interval){
    vector<vector<int>>result;
    int i=0;
    while(i<matrix.size() && matrix[i][0]<interval[0]){
        result.push_back({matrix[i][0],matrix[i][1]});
        i+=1; }
    while(i<matrix.size()&& matrix[i][0]<=interval[1]){
        interval[0]=min(interval[0],matrix[i][0]);
        interval[1]=max(interval[1],matrix[i][1]);
        i++;
    } result.push_back({interval[0],interval[1]});
    while(i<matrix.size()){
        result.push_back({matrix[i][0],matrix[i][1]});
        i+=1;}
 return result;}
int main() {
    vector<vector<int>>matrix={{1,2},{3,4},{6,7},{8,10},{12,16}};
    vector<vector<int>>temp=insertintervals(matrix,{5,8});
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].size();j++){
            cout<<temp[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}