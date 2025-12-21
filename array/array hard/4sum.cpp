#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> bf(vector<int> nums, int sum)
{
    vector<vector<int>> ans;
    set<vector<int>> s;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for(int l=k+1;l<n;l++)
            {

                if ((nums[i] + nums[j] + nums[k]+nums[l]) == sum)
                {
                    vector<int> n = {nums[i], nums[j], nums[k],nums[l]};
                    sort(n.begin(), n.end());
                    s.insert(n);
                }
            }
        }
    }}
    for (auto i : s)
        ans.push_back(i);
    return ans;
}
vector<vector<int>> hashing(vector<int> nums, int sum)
{
    vector<vector<int>> ans;
    set<vector<int>> s;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
       for(int k=i+1;k<n;k++)
        { unordered_map<int, int> map;
            for (int j = k + 1; j < n; j++)
          {  
        int target=sum-(nums[i]+nums[j]+nums[k]);
            if (map.find(target) != map.end())
            {   
                vector<int> na = {nums[i],nums[k], nums[j], target};
                 sort(na.begin(), na.end());
                s.insert(na);
                map[nums[j]];
            }
            else
                map[nums[j]];
        }
    }}
    for (auto i : s)
        ans.push_back(i);
    return ans;
}
vector<vector<int>>fourpointer(vector<int>&nums,int target){// only for sorted
    sort(nums.begin(),nums.end());
   vector< vector<int>>ans;
   set<vector<int>>s;
    int n=nums.size();
    for(int i=0;i<n;i++){
        
        for(int m=i+1;m<n;m++)
       { int j=m+1;
        int k=n-1;
         while(j<k)
         {int sum=nums[i]+nums[j]+nums[k]+nums[m];
            if(sum>target){
                k--;
            }
            else if(sum<target){
                j++;
            }
            else{
            vector<int>n={nums[i],nums[j],nums[k],nums[m]};
            sort(n.begin(),n.end());
            s.insert(n);
            k--;
            }
         }}}
    for(auto i:s) ans.push_back(i);
   return ans;
}


int main()
{
    vector<int> nums = {1,0,-1,0,-2,2,-3};
    int k = 0;
    // vector<vector<int>> b =fourpointer(nums, k);
    // vector<vector<int>>b=bf(nums,k);
    vector<vector<int>>b=hashing(nums,k);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}