#include <bits/stdc++.h>
using namespace std;
class mystack{
    vector<int>arr;
    int top=-1;
    public:
    void push(int a){
        top=top+1;
        arr.push_back(a);
    }
    void pop(){
        arr.pop_back();
        top--;
    }
    int topy(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
};
class myqueue{public:
    int arr[5]={0};
    int st=-1,end=-1;
    int size=0;
    void push(int a){
        if(size==0){
            st++;end++;
            arr[st]=a;
            size++;
        }
        else {st=(st+1)%5;
            size++;
     arr[st]=a;
  }
    }
    void pop(){
        
        if(size==1){
            arr[end]==0;
            st--;end--;size--;
        }
        else{size--;
         arr[end]=0;
         end=(end+1)%5;
    }
} 
   int topy(){
    return arr[end];
   }
   int sizey(){
    return size;
   }};
int main() {
    myqueue s;
    s.push(2);
   cout<< s.topy()<<endl;
    s.push(3);
    cout<<s.topy()<<endl;
    cout<<s.sizey()<<endl;
    s.push(4);
       cout<<s.sizey()<<endl;
    cout<<s.topy()<<endl;
    s.pop();
    cout<<s.sizey()<<endl;
    cout<<s.topy()<<endl;
    s.pop();
    cout<<s.sizey()<<endl;
    cout<<s.topy()<<endl;
    return 0;
}