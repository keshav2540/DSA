#include <bits/stdc++.h>
using namespace std;
class MedianFind {
        priority_queue<int,vector<int>,greater<int>>minheap;
        priority_queue<int>maxheap;
public:
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(maxheap.size()<minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
    }
    double findMedian() {
        if (maxheap.empty()) return 0.0;
        if(maxheap.size()!=minheap.size()) return maxheap.top();
       else return ((maxheap.top()+minheap.top())/2.0);
    }
};
int main() {
    MedianFind m;
    cout<<m.findMedian()<<endl;
    m.addNum(1);
    cout<<m.findMedian()<<endl;
    m.addNum(2);
    cout<<m.findMedian()<<endl;
    m.addNum(3);
    cout<<m.findMedian()<<endl;
    m.addNum(0);
    cout<<m.findMedian()<<endl;
    m.addNum(9);
     cout<<m.findMedian()<<endl;

    return 0;
}