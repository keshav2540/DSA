#include <bits/stdc++.h>
using namespace std;
int sol(string s,int k){
   int length=0;
    for(int i=0;i<s.size();i++){
        map<char,int>m; int change=0; int maxfrq=0;
        for(int j=i;j<s.size();j++){
            m[s[j]]++;
            maxfrq=max(maxfrq,m[s[j]]);
            change=j-i+1-maxfrq;  
        if(change<=k){
            length=max(length,j-i+1);
        } 
         else break;           
        }
    }return length;
}
int op( string nums, int k)
{
    int l = 0, r = 0, maxlength = 0; int maxfrq=0;
    map<char, int> m; int change=0;
    while (r < nums.size())
    { m[nums[r]]++;
            maxfrq=max(maxfrq,m[nums[r]]);
            change=r-l+1-maxfrq; 

        if(change > k)
        {  m[nums[l]]--;
            if(m[nums[l]]==0) m.erase(nums[l]);
            l++;  
        }
        if (change<= k)
        {
            maxlength = max(maxlength, r - l + 1);
        }
        r++;
    }
    return maxlength;
}
int main() {
    string s="AABBBA";
    int k=3;
    cout<<op(s,k);
    return 0;
}