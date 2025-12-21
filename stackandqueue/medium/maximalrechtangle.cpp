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
int maximalarea(vector<vector<int>>nums){int maximum=0;
    for(int i=0;i<nums.size();i++){
        maximum=max(maximum,largestarea(nums[i]));
    } return maximum;
}
int main() {
    vector<vector<int>>nums={{1,0,1,0,1},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    for(int i=0;i<5;i++){ int sum=0;
        for(int j=0;j<4;j++){
            sum+=nums[j][i];
            if(nums[j][i]==1) nums[j][i]=sum;
            else{
                nums[j][i]=0;sum=0;
            }
         }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout<<nums[i][j]<<" ";
            }cout<<endl;
         }
    cout<<maximalarea(nums);
    return 0;
}