#include <bits/stdc++.h>
using namespace std;
vector<int>aftercollision(vector<int>nums){
    stack<int>s;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=0){
            s.push(nums[i]);
        }
        else{ 
            while(!s.empty()&&s.top()<(abs(nums[i]))){
                  s.pop();}
                if(!s.empty()&&s.top()==abs(nums[i])) {s.pop();}
            if(s.empty()){
                while(i<nums.size() && nums[i]<0){
                    s.push(nums[i]);
                    i++;
                }

            }
        }
    } while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
     return ans;
}

int main() {
    vector<int>nums={4,7,1,1,2,-3,-7,17,15,-16,-18,-19};
    for(int i:aftercollision(nums)) cout<<i<<" ";
    return 0;
}