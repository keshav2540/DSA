#include <bits/stdc++.h>
using namespace std;
int celebrity1(vector<vector<int>>nums){
    vector<int>iknow;
    vector<int>knowme;
    for(int i=0;i<nums.size();i++){  int count1=0,count2=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i][j]==1)count1++;
            if(nums[j][i]==1)count2++;
         }
         iknow.push_back(count1);
         knowme.push_back(count2);
    }
    for(auto i:iknow)cout<<i<<" ";
    cout<<endl;
    for(auto i:knowme)cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<knowme.size();i++){
        if(knowme[i]==nums.size()-1&&iknow[i]==0)return i;
    }
 return -1;
}
int celebrity2(vector<vector<int>>nums){
    int top=0,down=nums.size()-1;
    while(top<down){
        if(nums[top][down]==1)top++;
       else if(nums[down][top]==1)down--;
       else {top--;
       down--;
} 
    }  
      if(top>down)return 0;
    for(int i=0;i<nums.size();i++){
        if(top==i && nums[top][i]==0);
        else if(nums[top][i]!=0||nums[i][top]!=1)return -1;
    } return top;
}

int main() {
vector<vector<int>>nums= { {0,1,1,0},{0,0,0,0},
{0,1,0,0},{1,1,0,0}};
cout<<celebrity2(nums);
   return 0;
}