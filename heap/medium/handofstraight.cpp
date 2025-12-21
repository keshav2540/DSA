#include <bits/stdc++.h>
using namespace std;
 bool isNStraightHand(vector<int>&h, int gs){
      if(h.size()%gs!=0) return false;
      priority_queue<int>pq;
      vector<pair<int,int>>vec(h.size()/gs,{-1,-1});
      for(int i=0;i<h.size();i++)pq.push(h[i]);
       for(int i=0;i<h.size();i++){
         int n=pq.top();
         bool found=false;
         for(auto &i:vec){
            cout<<i.first<<" "<<i.second<<"       ";
            if((i.first<gs||i.first==-1)&&((i.second-1)==n||(i.second)==-1)){
                    if(i.first==-1) i.first=0;
                    i.second=n;
                    i.first++;
                    found=true;
                 cout<<i.first<<" "<<i.second<<" "<<found<<endl;
                   pq.pop();
                    break;
            } 
            cout<<" not found"<<endl;  
         }cout<<endl<<endl<<endl;
         if(!found)return false;
     }
       return true;
 }

int main() {
vector<int>nums={1,1,2,2,3,3};
cout<<isNStraightHand(nums,2);
    return 0; 
}