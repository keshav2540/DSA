#include <bits/stdc++.h>
using namespace std;
 int kadans(vector<int>nums){ int sum=0,maxsum=0;
    for(int i=0;i<nums.size();i++){
    sum+=nums[i];
    maxsum=max(maxsum,sum);
    if(sum<0) sum=0;
    }
 return maxsum;
 }
 int profit(vector<int>num){int miniP=INT32_MAX,maxprofit=0,profit;
     for(int i=0;i<num.size();i++){
        miniP=min(num[i],miniP);
        profit=num[i]-miniP;
        maxprofit=max(maxprofit,profit);

 }
return maxprofit;    

 }

int main() {
    vector<int>nums={-2,-3,4,-1,2,1,5,-1,-4,12,-3};
    cout<<kadans(nums)<<endl;
     vector<int>num={7,1,5,3,6,4,9};
     cout<<profit(num);
    return 0;
}