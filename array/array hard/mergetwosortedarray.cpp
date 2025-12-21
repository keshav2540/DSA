//  array already sorted
 #include <bits/stdc++.h>
using namespace std;
// void twopointer
void optimal(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int st1 = n1-1, st2 = 0;
    while(st1>=0&& st2<n2){
        if(nums1[st1]>nums2[st2]){swap(nums1[st1],nums2[st2]); st1--; st2++;}
        else{ st1--;st2++;}
    } 
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}
 void helper(vector<int> &nums1, vector<int> &nums2,int gap,int n1,int n2){
    do{
    int st1=0; int st2=st1+gap;
    while(st2<(n1+n2)){
         if(st1>=n1&& st2<(n2+n1)){  
            if(nums2[st1-n1]>nums2[st2-n1]) {swap(nums2[st1-n1],nums2[st2-n1]); st1++; st2++;}
            else {st1++; st2++;}
         }
         else if (st1<n1&& st2<n1){
             if(nums1[st1]>nums1[st2]){swap(nums1[st1],nums1[st2]); st1++; st2++;}
        else{ st1++;st2++;}
         }
         else {
            if(nums1[st1]>nums2[st2-n1]) {swap(nums1[st1],nums2[st2-n1]); st1++; st2++;}
               else{ st1++;st2++;}
         }
  }
  if(gap==1) gap=0;
  else gap=(gap)/2+gap%2;
} while(gap>0);
 }
void mostoptimalgapmethod(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int gap=(n1+n2)/2+1;
    helper(nums1,nums2,gap,n1,n2);
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {0, 2, 6, 8, 9};
    mostoptimalgapmethod(nums1, nums2);
     for (int i : nums1)
            cout<< i << " ";
            cout<<endl;
    for (int i : nums2)
        cout << i << " ";
    return 0;
}