#include <bits/stdc++.h>
using namespace std;
 void pushinlast(stack<int>&st,int  element){
    if(st.empty()){ st.push(element); return;}
    int a=st.top();st.pop();
    pushinlast(st,element);
    st.push(a);
}
void reversestack(stack<int>&st){
    int a=st.top();st.pop();
     if(!st.empty())reversestack(st);
     if(st.empty()) {st.push(a); return;}
       pushinlast(st,a);
}
int main() {
    stack<int>st;
    st.push(1);
    st.push(4);
    st.push(6);
    st.push(5);
    st.push(3);
    st.push(78);
    st.push(100);
    st.push(2);
 reversestack(st);
 reversestack(st);
 while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
 }}