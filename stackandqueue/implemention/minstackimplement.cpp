#include <bits/stdc++.h>
using namespace std;
class minstack{
    int mini;
    stack<int>st;
   public: void push(int a){
        if(st.empty()){
            mini=a;
            st.push(a);
        }
        else{
            if(a>mini)st.push(a);
            else {
                st.push((2*a-mini));
                mini=a;
            }
        }}
       void pop(){
        if(st.empty()) return;
        else{
            int x=st.top();
            st.pop();
            if(x<mini){
                mini=2*mini-x;
            }
        }
       } 
       int top(){
        if(st.top()<mini) return mini;
        return st.top();
       }
       int getmini(){
        return mini;
       }
    
};
class myminstack{
    stack<pair<int,int>>s;
    public:
    void push(int a){
        if(s.empty()){
            s.push({a,a});
        }
        else{
            s.push({a,min(s.top().second,a)});
        }
    }
    void pop(){
        s.pop();
    }
    int top(){
       return s.top().first;
    }
    int getmini(){
       return s.top().second;
    }
};
int main() {
    minstack s;
    s.push(12);
    s.push(15);
    s.push(10);
    cout<<s.getmini()<<endl;
    s.pop();
   cout<<s.top()<<endl;
   cout<<s.getmini()<<endl;
    return 0;
}