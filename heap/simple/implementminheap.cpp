#include <bits/stdc++.h>
using namespace std;
 class maxheap{
    vector<int>heap;
  void heapifyup(int i){
     int parent=(i-1)/2;
     if(heap[parent]>heap[i]&& i>0 ){
        swap(heap[parent],heap[i]);
        heapifyup(parent);
     }}
     void heapifydown( int i){
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;
        if(heap[left]<=heap[largest] &&  left<heap.size()){
            largest=left;
        }
        if(heap[right]<=heap[largest] && right<heap.size()){
            largest=right;
        }
        if(largest!=i){
            swap(heap[i],heap[largest]);
            heapifydown(largest);
        }}
     public:
     void insert( int i){
        heap.push_back(i);
        heapifyup(heap.size()-1);
     }
     void remove(){
        if(heap.empty()){
            cout<<"empty heap";
        }
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        heapifydown(0);    
        }
        int getmax(){
            if(heap.empty()) return -1;
            return heap[0];
        } 
        void display(){
            for(auto i:heap) cout<<i<<" ";
            cout<<endl;
        }};
int main() {
    maxheap h;
    h.insert(50);
    h.display();
    cout<<h.getmax()<<endl;
    h.insert(40);
    cout<<h.getmax()<<endl;
    h.display();
    h.insert(30);
    cout<<h.getmax()<<endl;
    h.display();
    h.insert(10);
    cout<<h.getmax()<<endl;
    h.display();
    h.remove();
    cout<<h.getmax()<<endl;
    h.display();
    h.remove();
    cout<<h.getmax()<<endl;
    h.display();
    return 0;
}