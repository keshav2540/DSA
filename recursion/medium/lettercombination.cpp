#include <bits/stdc++.h>
using namespace std;
void combination(int ind,string s,vector<string>&ans,string combos[],string nums){
    if(nums.size()==ind){
         ans.push_back(s);
         return;
    }
    int digit=nums[ind]-'0';
    for(int i=0;i<combos[digit].size();i++){
        combination(ind+1,s+combos[digit][i],ans,combos,nums);
    }
}
int main() {
    string nums="3";
     string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
     string s="";
     vector<string>ans;
     combination(0,s,ans,combos,nums);
     for(auto i: ans) cout<<i<<endl;
    return 0;
}