#include <bits/stdc++.h>
using namespace std;
int lengthbf(string nums)
{int maxlength=0; 
    for(int i=0;i<nums.size();i++)
{       map<int,int>m;
    for(int j=i;j<nums.size();j++){
        if(m[nums[j]-'a']==1) break;
        m[nums[j]-'a']++;
maxlength=max(maxlength,j-i+1);}
} return maxlength;
}
int lengthbetter(string nums){
    vector<int>m(256,-1);
        int n=nums.size();
    int l=0,r=0,maxlen=0;
    while(r<n){
        if(m[nums[r]]!=-1){
            if(m[nums[r]]>=l){
                l=m[nums[r]]+1;
            } }
            maxlen=max(maxlen,r-l+1);
          m[nums[r]]=r;
          r++;    
    } return maxlen;
}

int main() {
    string nums="cadbzabcd";
    cout<<lengthbetter(nums);
    return 0;
}