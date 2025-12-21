#include <bits/stdc++.h>
using namespace std;
class data{public:
 int start,end,index;
 data( int start,int end,int index){
    this->start=start;
    this->end=end;
    this->index=index;
 }
};
bool compare(data a,data b){
    return  a.end<b.end;
}
vector<int>numberofmeeting(vector<data>nums){
    sort(nums.begin(),nums.end(),compare);
    vector<int>ans;
    ans.push_back(nums[0].index+1);
    int st=0,end=0;
    for(int i=0;i<nums.size();i++){
        if(nums[st].end<nums[end].start){
            ans.push_back(nums[end].index+1);
            st++;
        }
          end++;
    } return ans;
}

int main() {
    vector<data>nums={{0,5,0},{3,4,1},{1,2,2},{5,9,3},{5,7,4},{8,9,5}};
    for(auto i:numberofmeeting(nums)) cout<<i<<endl;

    return 0;
}