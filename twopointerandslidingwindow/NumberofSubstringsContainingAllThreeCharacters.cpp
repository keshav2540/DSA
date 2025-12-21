#include <bits/stdc++.h>
using namespace std;
int maxcountsubarraybf(string nums)
{
    int maxcount = 0;
    for (int i = 0; i < nums.size(); i++)
    { vector<int>hash(3,0);
        for (int j = i; j < nums.size(); j++)
        {  hash[nums[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){// maxcount++;
           maxcount+=(nums.size()-j);
           break;}
        }
    }
    return maxcount;
}
int maxcountsubarrayoptimal(string nums){
    int count=0;
    vector<int>m(3,-1);
    for(int i=0;i<nums.size();i++){
        m[nums[i]-'a']=i;
        if(m[0]!=-1 && m[1]!=-1 && m[2]!=-1){
            count+=min(min(m[0],m[1]),m[2])+1;
        }
    } return count;
}


int main() {
    string nums="bbacba";
    cout<<maxcountsubarrayoptimal(nums);
    return 0;
}