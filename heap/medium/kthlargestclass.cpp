#include <bits/stdc++.h>
using namespace std;
class kthlargest{
    priority_queue<int,vector<int>,greater<int>>heap;
    int k; 
    public:
    kthlargest(int k,vector<int>nums){
        this->k=k;
        for(auto i:nums) heap.push(i);
        while(heap.size()>k)heap.pop();
    }
    int add(int l){
        heap.push(l);
        if(heap.size()>k)heap.pop();
        return heap.top();
    }
};
int main() {
         kthlargest s(3,{4,5,8,2});
         cout<<endl<<s.add(0);
         cout<<endl<<s.add(8);
         cout<<endl<<s.add(4);
         cout<<endl<<s.add(9);
    return 0;
}