#include <bits/stdc++.h>
using namespace std;
class mystack{public:
     queue<int>q;
     void push(int a){
        int l=q.size();
        q.push(a);
        for(int i=1;i<=l;i++){
            q.push(q.front());
            q.pop();
        }
     }
     void pop(){
        q.pop();
     }
     int topy(){
        return q.front();
     }
     int sizey(){
        return q.size();
     }
};
class myqueue{public:
     stack<int>s1;
     stack<int>s2;
     void push(int a){
       while(s1.size()){
        s2.push(s1.top());
        s1.pop();
       }
       s2.push(a);
       while(s2.size()){
        s1.push(s2.top());
        s2.pop();
       }
     }
     void pop(){
        s1.pop();
     }
     int topy(){return s1.top();
     }
     int sizey(){
        return s1.size();
     }
};

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

