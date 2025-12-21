#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>powerset(vector<int>nums){
    vector<vector<int>>ans;
    for(int i=0;i<(2*2*2*2*2);i++){
        vector<int>temp;
        for(int j=0;j<nums.size();j++){
            if(i&(1<<j)){temp.push_back(nums[j]); }
        } ans.push_back(temp);
    } return ans;

}

int main() {
    vector<int>nums={1,2,3,4,5};
    vector<vector<int>>mat=powerset(nums);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}