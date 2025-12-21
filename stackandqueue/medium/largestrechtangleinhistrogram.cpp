#include <bits/stdc++.h>
using namespace std;
// find nse and pse in apply formula=arr[i]*(nseidx-pseidx-1) 
int largestarea(vector<int>nums){
    stack<int>st;int nse,pse,maxarea=0;
    for(int i=0;i<nums.size();i++){
    while(!st.empty()&& nums[st.top()]>nums[i]){
        int element=st.top();
        st.pop();
        nse=i;
        pse=st.empty()?-1:st.top();
maxarea=max(maxarea,(nse-pse-1)*nums[element]);}
 st.push(i);}
 while(!st.empty()){
    nse=nums.size();
    int element=st.top();
    st.pop();
    pse=st.empty()?-1:st.top();
maxarea=max(maxarea,(nse-pse-1)*nums[element]);}
  return maxarea;
    }

int main() {
    vector<int>nums={3,2,10,11,5,10,6,3};
    cout<<largestarea(nums);
    return 0;
}