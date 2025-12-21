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

                if ((nums[i] + nums[j] + nums[k]) == sum)
                {
                    vector<int> n = {nums[i], nums[j], nums[k]};
                    sort(n.begin(), n.end());
                    s.insert(n);
                }
            }
        }
    }
    for (auto i : s)
        ans.push_back(i);
    return ans;
}
vector<vector<int>> hashing(vector<int> nums, int sum)
{
    vector<vector<int>> ans;
    set<vector<int>> s;
    unordered_map<int, int> map;
    int target;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        target = -nums[i];
        for (int j = i + 1; j < n; j++)
        {
            if (map.find(target - nums[j]) != map.end())
            {
                vector<int> n = {nums[i], nums[j], target - nums[j]};
                sort(n.begin(), n.end());
                s.insert(n);
                map[nums[j]];
            }
            else
                map[nums[j]];
        }
    }
    for (auto i : s)
        ans.push_back(i);
    return ans;
}
vector<vector<int>>threepointer(vector<int>&nums,int target){// only for sorted
    sort(nums.begin(),nums.end());
   vector< vector<int>>ans;
   set<vector<int>>s;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
         while(j<k)
         {int sum=nums[i]+nums[j]+nums[k];
            if(sum>target){
                k--;
            }
            else if(sum<target){
                j++;
            }
            else{
            vector<int>n={nums[i],nums[j],nums[k]};
            sort(n.begin(),n.end());
            s.insert(n);
            k--;
            }
         }}
    for(auto i:s) ans.push_back(i);
   return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, 4,-4,-5,5,-9,-8,-1};
    int k = 0;
    vector<vector<int>> b =threepointer(nums, k);
    // vector<vector<int>>b=bf(nums,k);
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