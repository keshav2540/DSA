#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>mergeoverlappinginterval(vector<vector<int>>nums){
    vector<vector<int>>ans;
    int k=0;
    ans.push_back({nums[0][0],nums[0][1]});
    sort(nums.begin(),nums.end());
    int r=nums.size();
    int c=nums[0].size();
    for(int i=0;i<r;i++){
        if(ans[k][1]>=nums[i][0]){
            if(nums[i][1]>ans[k][1]) ans[k][1]=nums[i][1];
        }
        else{   
            k++;
             ans.push_back({nums[i][0],nums[i][1]});
        }
    }
 return ans;
}

int main() {
    vector<vector<int>>nums={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    vector<vector<int>>num=mergeoverlappinginterval(nums);
    for(int i=0;i<num.size();i++) 
   { for(int j=0;j<num[i].size();j++)cout<<num[i][j]<<" ";
cout<<endl;}

    return 0;
}