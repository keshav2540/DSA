#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> nums, int mid, int student){
    int sum=0, countstudent=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum>mid){
            sum=nums[i];
            countstudent++;
        }
    }
    if(countstudent>=student) return true;
    return false;
}
int bookallocation(vector<int> nums, int student)
{int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);
    while (low <= high)
{     
       int mid = (low + high) / 2;
    if (ispossible(nums, mid ,student))
    {
        low = mid +1;
    }
    else{ high = mid - 1;}
}

    return low;
}

int main()
{
    vector<int> nums = {25,46,28,49,24};
int student=4;
    cout << bookallocation(nums, student);
    return 0;
}