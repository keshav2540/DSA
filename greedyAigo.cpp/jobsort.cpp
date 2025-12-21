#include <bits/stdc++.h>
using namespace std;
class job{public:
    int id,deadline,profit;
    job(int id ,int deadline,int profit){
        this->id=id;
        this->deadline=deadline;
        this->profit=profit;
    }
};
bool compare(job a, job b){return a.profit>b.profit;}

int main() {
    vector<job>nums={{3,6,70},{0,2,80},{4,6,65},{2,5,60},{5,4,25},{8,2,22},{1,4,20},{7,2,10}};
    sort(nums.begin(),nums.end(),compare);
    vector<int>arr(7,-1);
     int profit=0,count=0;
    for(int i=0;i<nums.size();i++){
    for(int j=nums[i].deadline;j>=0;j--){
        if(arr[j]==-1){
            arr[j]=nums[i].deadline;
            count++;
            profit+=nums[i].profit;
            break;
        }
    }
    }cout<<profit;
    return 0;
}