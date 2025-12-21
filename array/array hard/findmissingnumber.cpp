/* good for you you learn after bitmaniulation*/
#include <bits/stdc++.h>
using namespace std;
vector<int>findmissing(vector<int>nums){
    vector<int>ans;
    int n=nums.size();
    int arrsum=0,arrsq=0,sq=0,sum=0;
    for(int i=0;i<n;i++){
        arrsum+=nums[i];
        sum+=i+1;
        sq+=(i+1)*(i+1);
        arrsq+=nums[i]*nums[i];
    }
    int k=sum-arrsum;
    int l=(sq-arrsq)/k;
    ans.push_back(l-(k+l)/2);
    ans.push_back((k+l)/2);
    return ans;
}

vector<int>findmissingrepeatingnumber(vector<int>nums){
    long long n=nums.size();
    int  x=0;
    for(int i=0;i<n;i++){
        x=x^nums[i];
        x=x^(i+1);
    }
    int /*bitno*/number=x& ~(x-1);
    // while(1){
    //     if((x &(1<<bitno))!=0){
    //         break;
    //     }
    //     else
    //     bitno++;
    // }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++)
        {if((nums[i]&(/*1<<bitno*/number))!=0){
            one=one^nums[i];
        }else{
            zero=zero^nums[i];
        }
    }
    for(int i=0;i<=n;i++)
        {if((i&(/*1<<bitno*/number))!=0){
            one=one^i;
        }else{
            zero=zero^i;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i]==zero) count++;
    }
    if(count==2) return {zero,one};
     return {one,zero};

}
int main() {
    vector<int>nums={4,3,6,2,1,1,5};
    for(int i:findmissingrepeatingnumber(nums)) cout<<i<<" ";
    return 0;
}