#include <bits/stdc++.h>
using namespace std;
bool sellallcustor(vector<int>nums){
    int five=0,ten=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==5){
            five++;
        }
        else if(nums[i]==10){
            if(five){
                five--;
                ten++;
            }
            else return false;
        }
        else if(nums[i]==20){
            if(five&&ten){
                five--;
                ten--;
            }
            else if(five>=3){
                five=five-3;
            }
            else return false;
        }
        else return false;
    } return true;
}
int main() {
    vector<int>nums={5,5,5,10,20};// prize is 5;
    cout<<sellallcustor(nums);
    return 0;
}